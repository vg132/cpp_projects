// DlgOptions.cpp : implementation file
//

#include "stdafx.h"
#include "gp3trackinstaller.h"
#include "DlgOptions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOptions dialog


CDlgOptions::CDlgOptions(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOptions::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgOptions)
	m_bOverwrite = FALSE;
	m_bRemove = FALSE;
	m_bShowGp3Form = FALSE;
	m_bShowReport = FALSE;
	m_bTempFolder = FALSE;
	m_szFolder = _T("");
	//}}AFX_DATA_INIT
}


void CDlgOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOptions)
	DDX_Control(pDX, IDC_COMBO_LANGUAGE, m_Language);
	DDX_Check(pDX, IDC_CHECK_OVERWRITE, m_bOverwrite);
	DDX_Check(pDX, IDC_CHECK_REMOVE, m_bRemove);
	DDX_Check(pDX, IDC_CHECK_SHOW_GP3FORM, m_bShowGp3Form);
	DDX_Check(pDX, IDC_CHECK_STATUS_REPORT, m_bShowReport);
	DDX_Check(pDX, IDC_CHECK_TEMP_FOLDER, m_bTempFolder);
	DDX_Text(pDX, IDC_EDIT_UNZIP_PATH, m_szFolder);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOptions, CDialog)
	//{{AFX_MSG_MAP(CDlgOptions)
	ON_BN_CLICKED(IDC_CHECK_TEMP_FOLDER, OnCheckTempFolder)
	ON_BN_CLICKED(IDC_BUTTON_UNZIP_BROWSE, OnButtonUnzipBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOptions message handlers

void CDlgOptions::OnOK() 
{
	UpdateData(TRUE);

	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ExtractDir",
												m_szFolder);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"RemoveExtract",
												m_bRemove);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ExtractToTemp",
												m_bTempFolder);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"OverwriteFiles",
												m_bOverwrite);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ShowReport",
												m_bShowReport);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ShowGp3Form",
												m_bShowGp3Form);

	m_pLanguage=(char*)m_Language.GetItemDataPtr(m_Language.GetCurSel());

	if(m_pLanguage!=NULL)
		m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
													"Software\\VG Software\\Gp3 Track Installer",
													"Language",
													m_pLanguage);


	char* lpVoid=NULL;
	for(int i=0;i<m_Language.GetCount();i++)
	{
		lpVoid=(char*)m_Language.GetItemDataPtr(i);
		if(lpVoid!=NULL)
			delete[] lpVoid;
	}

	CDialog::OnOK();
}

void CDlgOptions::OnCancel() 
{
	CDialog::OnCancel();
}

BOOL CDlgOptions::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetDlgItemText(IDC_STATIC_ZIP_SETTINGS,m_pLang->GetText(m_pLang->ZIP_SETTINGS_FRAME));
	SetDlgItemText(IDC_CHECK_TEMP_FOLDER,m_pLang->GetText(m_pLang->EXTRACT_TO_TEMP));
	SetDlgItemText(IDC_STATIC_EXTRACT_TO,m_pLang->GetText(m_pLang->EXTRACT_TO));
	SetDlgItemText(IDC_CHECK_REMOVE,m_pLang->GetText(m_pLang->REMOVE_FILES));
	SetDlgItemText(IDC_STATIC_MISC_SETTINGS,m_pLang->GetText(m_pLang->MISC_SETTINGS_FRAME));
	SetDlgItemText(IDC_CHECK_OVERWRITE,m_pLang->GetText(m_pLang->ALWAYS_OVERWRITE));
	SetDlgItemText(IDC_CHECK_STATUS_REPORT,m_pLang->GetText(m_pLang->SHOW_REPORT));
	SetDlgItemText(IDC_CHECK_SHOW_GP3FORM,m_pLang->GetText(m_pLang->SHOW_GP3FORM));
	SetDlgItemText(IDC_STATIC_LANGUAGE,m_pLang->GetText(m_pLang->SELECT_LANGUAGE));
	SetWindowText(m_pLang->GetText(m_pLang->SETTINGS_CAPTION));

	FindLanguageFiles();


	m_szFolder=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ExtractDir",
												(CString)"c:\\");
	m_bRemove=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"RemoveExtract",
												TRUE);
	m_bTempFolder=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ExtractToTemp",
												TRUE);
	m_bOverwrite=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"OverwriteFiles",
												FALSE);
	m_bShowReport=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ShowReport",
												TRUE);
	m_bShowGp3Form=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ShowGp3Form",
												TRUE);
	m_pLanguage=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"Language",
												"");

	char* pBuffer=new char[_MAX_PATH];
	GetPrivateProfileString("INFO","LANGUAGE","English",pBuffer,_MAX_PATH,m_pLanguage);
	
	int iPos=m_Language.FindString(-1,pBuffer);
	if(iPos>=0)
		m_Language.SetCurSel(iPos);
	else
		m_Language.SetCurSel(m_Language.FindString(-1,"English"));

	delete[] pBuffer;
	delete[] m_pLanguage;
	UpdateData(FALSE);
	OnCheckTempFolder();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgOptions::Init(CLanguage *lang)
{
	m_pLang=lang;
}

void CDlgOptions::OnCheckTempFolder() 
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC_EXTRACT_TO)->EnableWindow(!m_bTempFolder);
	GetDlgItem(IDC_EDIT_UNZIP_PATH)->EnableWindow(!m_bTempFolder);
	GetDlgItem(IDC_BUTTON_UNZIP_BROWSE)->EnableWindow(!m_bTempFolder);
}

char* CDlgOptions::BrowseForFolders(char *title)
{
	char* pPath;
	BROWSEINFO bff;
	LPITEMIDLIST pidl;
	
	pPath=new char[_MAX_PATH];

	bff.hwndOwner				= this->m_hWnd;
	bff.iImage					= 0;
	bff.lParam					= 0;
	bff.lpszTitle				= title;
	bff.pidlRoot				= NULL;
	bff.ulFlags					= BIF_RETURNONLYFSDIRS|BIF_EDITBOX;
	bff.pszDisplayName	= pPath;
	bff.lpfn						= NULL;

	pidl=SHBrowseForFolder(&bff);
	if (pidl)
	{
		SHGetPathFromIDList(pidl,pPath);
		return(pPath);
	}

	delete[] pPath;
	return(NULL);
}

void CDlgOptions::OnButtonUnzipBrowse() 
{
	char* pBuffer=NULL;
	pBuffer=BrowseForFolders("Select destination directory");
	if(pBuffer!=NULL)
		SetDlgItemText(IDC_EDIT_UNZIP_PATH,pBuffer);	
}

void CDlgOptions::FindLanguageFiles()
{
	WIN32_FIND_DATA wfd;
	HANDLE hFile;
	int iRetVal=0;
	int iLoop=0;
	char* pBuffer=new char[_MAX_PATH];
	char* pLanguage;
	char* pDir=new char[_MAX_PATH];

	GetModuleFileName(NULL,pDir,_MAX_PATH);
	for(iLoop=strlen(pDir);iLoop>=1;iLoop--)
	{
		if(pDir[iLoop]=='\\')
		{
			pDir[iLoop+1]='\0';
			break;
		}
	}
	strcat(pDir,"language\\");
	strcpy(pBuffer,pDir);
	strcat(pBuffer,"*.ini");

	hFile=FindFirstFile(pBuffer,&wfd);
	delete[] pBuffer;
	if(hFile==INVALID_HANDLE_VALUE)
	{
		delete[] pDir;
		delete[] pBuffer;
		m_Language.AddString("English");
		m_Language.SetItemData(0,NULL);
		return;
	}
	do
	{
		if(wfd.cFileName[0]!='.')
		{
			pLanguage=new char[100];
			pBuffer=new char[_MAX_PATH];
			sprintf(pBuffer,"%s%s",pDir,wfd.cFileName);
			GetPrivateProfileString("INFO","LANGUAGE",wfd.cFileName,pLanguage,100,pBuffer);
			iLoop=m_Language.AddString(pLanguage);
			delete[] pLanguage;
			m_Language.SetItemDataPtr(iLoop,pBuffer);
		}

	}while(FindNextFile(hFile,&wfd));
	delete[] pDir;
}
