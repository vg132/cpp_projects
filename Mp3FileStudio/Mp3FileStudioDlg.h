// Mp3FileStudioDlg.h : header file
//

#if !defined(AFX_MP3FILESTUDIODLG_H__15E17FED_E98E_4F79_9F96_074E7A218022__INCLUDED_)
#define AFX_MP3FILESTUDIODLG_H__15E17FED_E98E_4F79_9F96_074E7A218022__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMp3FileStudioDlg dialog

#include "FileListView.h"
#include "FileComboBox.h"

#include "RegEdit.h"
#include "Structs.h"

#include "TagEdit.h"
#include "AutoTagEdit.h"
#include "AutoFileName.h"
#include "FileOrginizer.h"
#include "Settings.h"

#include "SystemImageList.h"

class CMp3FileStudioDlg : public CDialog, private CSystemImageList
{
private:
	UINT m_Message;
	void BuildToolbar();
	CToolBarCtrl m_Toolbar;
	CRegEdit m_RegEdit;
	int m_CurrentView;
	CString m_ToolBarStatus;
	CString m_File;
	CString m_WinAmpPath;
	CPropertySheet m_PropertySheet;

	CTagEdit m_TagEdit;
	CAutoTagEdit m_AutoTagEdit;
	CAutoFileName m_AutoFileName;
	CFileOrginizer m_FileOrginizer;
	CSettings m_Settings;
	bool m_AlwaysOnTop;
public:
	CMp3FileStudioDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMp3FileStudioDlg)
	enum { IDD = IDD_MP3FILESTUDIO };
	CFileComboBox	m_DriveList;
	CFileListView	m_FileList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMp3FileStudioDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMp3FileStudioDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUp1lvl();
	afx_msg void OnList();
	afx_msg void OnReport();
	afx_msg void OnBigIcons();
	afx_msg void OnHelp();
	afx_msg void OnAppAbout();
	afx_msg void OnHelpOnline();
	afx_msg void OnViewRefresh();
	afx_msg void OnFileSave();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnViewAlwaysontop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3FILESTUDIODLG_H__15E17FED_E98E_4F79_9F96_074E7A218022__INCLUDED_)
