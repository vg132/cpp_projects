// NewConfigDlg.cpp : implementation file
//

#include "stdafx.h"
#include "F1C_ReplaySaver.h"
#include "NewConfigDlg.h"


// CNewConfigDlg dialog

IMPLEMENT_DYNAMIC(CNewConfigDlg, CDialog)
CNewConfigDlg::CNewConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewConfigDlg::IDD, pParent)
	, m_Name(_T(""))
	, m_ReplayDirectory(_T(""))
	, m_Executable(_T(""))
{
}

CNewConfigDlg::~CNewConfigDlg()
{
}

void CNewConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
	DDX_Text(pDX, IDC_EDIT_REPLAY_DIRECTORY, m_ReplayDirectory);
	DDX_Text(pDX, IDC_EDIT_EXECUTABLE, m_Executable);
}


BEGIN_MESSAGE_MAP(CNewConfigDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_DIRECTORY, OnBnClickedButtonBrowseDirectory)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_EXECUTABLE, OnBnClickedButtonBrowseExecutable)
END_MESSAGE_MAP()


// CNewConfigDlg message handlers

void CNewConfigDlg::OnBnClickedButtonOk()
{
	OnOK();
}

void CNewConfigDlg::OnBnClickedButtonCancel()
{
	OnCancel();
}

void CNewConfigDlg::OnBnClickedButtonBrowseDirectory()
{
	char path[_MAX_PATH];
	BROWSEINFO bff;
	LPITEMIDLIST pidl;

	UpdateData(TRUE);

	bff.hwndOwner				= this->m_hWnd;
	bff.iImage					= 0;
	bff.lParam					= 0;
	bff.lpszTitle				= "Select replay folder";
	bff.pidlRoot				= NULL;
	bff.ulFlags					= BIF_RETURNONLYFSDIRS|BIF_EDITBOX;
	bff.pszDisplayName	= path;
	bff.lpfn						= NULL;

	pidl=SHBrowseForFolder(&bff);
	if (pidl)
	{
		SHGetPathFromIDList(pidl,path);
		m_ReplayDirectory=path;
		UpdateData(FALSE);
	}
}

void CNewConfigDlg::OnBnClickedButtonBrowseExecutable()
{
	CFileDialog fd(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"Executable files|*.exe;*.lnk;*.com;*.bat;*.msi||",this);
	if(fd.DoModal()==IDOK)
	{
		m_Executable=fd.GetOFN().lpstrFile;
		m_StartupDirectory=m_Executable.Mid(0,m_Executable.GetLength()-fd.GetFileName().GetLength());
		UpdateData(FALSE);
	}
}
