// AddDirectoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "F1C_ReplaySaver.h"
#include "AddDirectoryDlg.h"


// CAddDirectoryDlg dialog

IMPLEMENT_DYNAMIC(CAddDirectoryDlg, CDialog)
CAddDirectoryDlg::CAddDirectoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddDirectoryDlg::IDD, pParent)
	, m_Executable(_T(""))
	, m_Directory(_T(""))
	, m_Name(_T(""))
{
}

CAddDirectoryDlg::~CAddDirectoryDlg()
{
}

void CAddDirectoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_EXECUTABLE, m_Executable);
	DDX_Text(pDX, IDC_EDIT_REPLAY_DIRECTORY, m_Directory);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
}


BEGIN_MESSAGE_MAP(CAddDirectoryDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_EXECUTABLE, OnBnClickedButtonBrowseExecutable)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_DIRECTORY, OnBnClickedButtonBrowseDirectory)
END_MESSAGE_MAP()


// CAddDirectoryDlg message handlers

void CAddDirectoryDlg::OnBnClickedButtonOk()
{
	OnOK();
}

void CAddDirectoryDlg::OnBnClickedButtonCancel()
{
	OnCancel();
}

void CAddDirectoryDlg::OnBnClickedButtonBrowseExecutable()
{
	CFileDialog fd(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"Executable files|*.exe;*.lnk;*.com;*.bat;*.msi||",this);
	if(fd.DoModal()==IDOK)
	{
		m_Executable=fd.GetOFN().lpstrFile;
		UpdateData(FALSE);
	}
}

void CAddDirectoryDlg::OnBnClickedButtonBrowseDirectory()
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
		m_Directory=path;
		UpdateData(FALSE);
	}
}
