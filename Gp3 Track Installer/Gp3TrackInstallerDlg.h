// Gp3TrackInstallerDlg.h : header file
//

#if !defined(AFX_GP3TRACKINSTALLERDLG_H__7A175BB5_2C8E_44BF_BB89_5D0B54836FB7__INCLUDED_)
#define AFX_GP3TRACKINSTALLERDLG_H__7A175BB5_2C8E_44BF_BB89_5D0B54836FB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGp3TrackInstallerDlg dialog

#include "List.h"
#include "RegEdit.h"
#include "LogTrace.h"
#include "Language.h"
#include "DlgOptions.h"
#include "DlgReport.h"
#include "DlgProgress.h"
#include "Gp3Info.h"
#include "InfoZip/InfoZip.h"
#include "Banner/BannerStatic.h"


class CGp3TrackInstallerDlg : public CDialog
{
private:
	List<char> m_JamList;
	CRegEdit m_RegEdit;
	CLogTrace m_Log;
	CLanguage m_Language;
	char* m_pExtractDirectory;

	BOOL m_bOverwrite;
	BOOL m_bShowReport;
	BOOL m_bShowGp3Form;
	BOOL m_bRemove;
	BOOL m_bTempFolder;
	CString m_szExtractPath;
	char* m_pLanguage;

	void InstallJams(CString szGp3Path);
	char* BrowseForFolders(char* title);
	bool ReadJamTable(CFile* pFile, int iJamStart);
	int GetJamStart(CFile* pFile);
	void EnableTrackDir(BOOL bEnable);
	bool CreateSubDirectorys(char* dir);
	bool FileExists(CString file);
	bool FileExists(char* file);
	int GetJamType(char* file);
	char* GetDirectory(char* file);
	void CopyTrack();
	void SaveSettings();
	void ConvertFile(char* file, bool bDelete);
	void EnableInstall(bool bEnable);
	bool Unzip(char* file);
	char* SearchFile(char* dir, char* file);
	char* SearchDirectory(char* dir, char* file);
	int FindMenuItem(CMenu* Menu, LPCTSTR MenuString);
	void LoadSettings();
public:
	void ShowGp3Info();
	void LoadText();
	void RemoveExtractDirectory();
	void Error(char* pFunction);
	bool ClearAndRemoveDirectory(char* dir);
	char* m_pGp3TrackFile;
	CGp3TrackInstallerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGp3TrackInstallerDlg)
	enum { IDD = IDD_GP3TRACKINSTALLER_DIALOG };
	BOOL	m_bTrackDir;
	CString	m_TrackFile;
	CString m_Gp32kPath;
	CString m_Gp3Path;
	CString m_TrackDir;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGp3TrackInstallerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGp3TrackInstallerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonGp3Browse();
	afx_msg void OnButtonGp32kBrowse();
	afx_msg void OnButtonInstallGp3();
	afx_msg void OnButtonInstallGp32k();
	afx_msg void OnButtonInstallBoth();
	afx_msg void OnButtonTrackdirBrowse();
	afx_msg void OnClose();
	afx_msg void OnCheckTrackdirEnable();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnHelpHelp();
	afx_msg void OnHelpOnline();
	afx_msg void OnFileOpen();
	afx_msg void OnFileClose();
	afx_msg void OnFileSettings();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GP3TRACKINSTALLERDLG_H__7A175BB5_2C8E_44BF_BB89_5D0B54836FB7__INCLUDED_)
