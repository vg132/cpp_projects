#include "StdAfx.h"
#include "wndproc.hpp"

void WndProc::OnNotify(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	if(wParam==IDC_LIST_PROGRAM_KEYSTROKE)
	{
		LV_DISPINFO *pLvdi=(LV_DISPINFO*)lParam;
		NM_LISTVIEW *pNm=(NM_LISTVIEW*)lParam;
		switch(pLvdi->hdr.code)
		{
			case LVN_COLUMNCLICK:
			{
				ListView_SortItems(pNm->hdr.hwndFrom,CompareFunc,(LPARAM)(pNm->iSubItem));
				if(m_Order==ORDER_ASC)
					m_Order=ORDER_DESC;
				else
					m_Order=ORDER_ASC;
				break;
			}
		}
	}
}

void WndProc::OnSize(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	if(wParam==SIZE_MINIMIZED)
	{
		ShowWindow(m_hWnd,SW_HIDE);
	}
}

void WndProc::OnShellNotify(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	if(lParam==WM_LBUTTONDBLCLK)
	{
		ShowWindow(m_hWnd,SW_SHOWNORMAL);
		SetForegroundWindow(m_hWnd);

		sprintf(m_Buffer,"Keystrokes: %d",m_Counter.GetKeyStrokes());
		lstrcpy(m_NotifyIconData.szTip, m_Buffer);
		SetWindowText(m_hKeyStrokes,m_Buffer);
		UpdateList();
	}
}

void WndProc::OnInitDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	m_hDataFile=GetDlgItem(hWnd,IDC_EDIT_DATA_PATH);
	m_hList=GetDlgItem(hWnd,IDC_LIST_PROGRAM_KEYSTROKE);
	m_hCheckProgram=GetDlgItem(hWnd,IDC_CHECK_PROGRAM_INFO);
	m_hShowFullPath=GetDlgItem(hWnd,IDC_CHECK_FULL_PATH);
	m_hKeyStrokes=GetDlgItem(hWnd,IDC_STATIC_KEYSTROKES);

	SendMessage(m_hList,LVM_SETEXTENDEDLISTVIEWSTYLE,0,LVS_EX_FULLROWSELECT);

	// Add headers to listbox.
	LV_COLUMN LvCol;
	memset(&LvCol,0,sizeof(LvCol));
	LvCol.mask=LVCF_TEXT|LVCF_WIDTH|LVCF_SUBITEM;
	LvCol.pszText="Keys";
	LvCol.cx=70;
	SendMessage(m_hList,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol);
	LvCol.cx=190;
	LvCol.pszText="Program";
	SendMessage(m_hList,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol);
}

void WndProc::OnCommand(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	switch(LOWORD(wParam))
	{
		case IDC_CHECK_FULL_PATH:
		{
			m_Counter.SetShowFullPath(Button_GetCheck(m_hShowFullPath));
			UpdateList();
			break;
		}
		case IDC_CHECK_PROGRAM_INFO:
		{
			m_Counter.SetCheckProgram(Button_GetCheck(m_hCheckProgram));
			break;
		}
		case IDC_BUTTON_BROWSE:
		{
			OPENFILENAME ofn;
			char szFile[_MAX_DIR];

			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = m_hWnd;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = "Keystore Datafile (*.kdt)\0*.kdt\0All Files (*.*)\0*.*\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.lpstrDefExt="kdt";
			ofn.Flags = OFN_PATHMUSTEXIST;
			if (GetOpenFileName(&ofn)==TRUE)
			{
				SetWindowText(m_hDataFile,szFile);
				m_Counter.SetDataFile(szFile);
				SaveDataPath();
			}
		}
	}
}