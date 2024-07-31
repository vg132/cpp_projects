// New Track InstallDlg.h : header file
//

#if !defined(AFX_NEWTRACKINSTALLDLG_H__E3681866_CFFA_11D3_999B_0008C7636E27__INCLUDED_)
#define AFX_NEWTRACKINSTALLDLG_H__E3681866_CFFA_11D3_999B_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNewTrackInstallDlg dialog

class CNewTrackInstallDlg : public CDialog
{
// Construction
public:
	CNewTrackInstallDlg(CWnd* pParent = NULL);	// standard constructor
	int iCurItem;
	CString cGp2FormName;
// Dialog Data
	//{{AFX_DATA(CNewTrackInstallDlg)
	enum { IDD = IDD_NEWTRACKINSTALL_DIALOG };
	CListCtrl	m_JamFiles;
	CListCtrl	m_TrackFile;
	CButton	m_NextButton;
	CString	m_Gp2Dir;
	CString	m_SetupFile;
	CString	m_WelcomeText;
	CString	m_Gp2Form;
	CString	m_Summary;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewTrackInstallDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNewTrackInstallDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCancel();
	afx_msg void OnNext();
	afx_msg void OnBack();
	afx_msg void OnSetupBrowse();
	afx_msg void OnGp2DirBrowse();
	afx_msg void OnAddJam();
	afx_msg void OnAddTrack();
	afx_msg void OnRemoveAll();
	afx_msg void OnRemoveJam();
	afx_msg void OnRemoveTrack2();
	afx_msg void OnAddGp2Form();
	afx_msg void OnRemoveGp2Form();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void CopyBinFile();
	void CopyGp2Form();
	void CopyTrackFile();
	void CopyJamFiles(CString cTempDir);
	CString GetFileName(CString cFileName);
	void DeleteTempDir(CString cDir);
	void AddFiles();
	CString CreateTempDir();
	void MakeSummary();
	CString RegGetValue(CString cKey,CString cValue);
	void RegSaveValue(CString cKey,CString cValue,CString cData);
	void ConvertFile(CString cFileName,bool bDelete);
	void Show4(bool Show);
	void Show3(bool Show);
	void Show2(bool Show);
	void Show1(bool Show);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTRACKINSTALLDLG_H__E3681866_CFFA_11D3_999B_0008C7636E27__INCLUDED_)
