// Gp3TrackInstaller.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Gp3TrackInstaller.h"
#include "Gp3TrackInstallerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGp3TrackInstallerApp

BEGIN_MESSAGE_MAP(CGp3TrackInstallerApp, CWinApp)
	//{{AFX_MSG_MAP(CGp3TrackInstallerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGp3TrackInstallerApp construction

CGp3TrackInstallerApp::CGp3TrackInstallerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGp3TrackInstallerApp object

CGp3TrackInstallerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGp3TrackInstallerApp initialization

BOOL CGp3TrackInstallerApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CGp3TrackInstallerDlg dlg;

	char* pLongPathName=new char[_MAX_PATH];
	GetLongPathName(m_lpCmdLine,pLongPathName,_MAX_PATH);

	// if it's not a .dat file (track file)
	if(strcmpi(&pLongPathName[strlen(pLongPathName)-4],".dat"))
	{
		dlg.m_pGp3TrackFile=NULL;
	}
	else
	{
		dlg.m_pGp3TrackFile=new char[_MAX_PATH];
		strcpy(dlg.m_pGp3TrackFile,pLongPathName);
	}
	delete[] pLongPathName;

	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
