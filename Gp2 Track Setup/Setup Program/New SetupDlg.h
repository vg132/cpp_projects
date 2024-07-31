// New SetupDlg.h : header file
//

#if !defined(AFX_NEWSETUPDLG_H__9D17ECA6_D0C2_11D3_999B_0008C7636E27__INCLUDED_)
#define AFX_NEWSETUPDLG_H__9D17ECA6_D0C2_11D3_999B_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNewSetupDlg dialog

class CNewSetupDlg : public CDialog
{
// Construction
public:

	int iCurPos;
	CString m_Gp2Dir;
	CString m_ExtDir;
	char szModule[260];

	int iTrackPos;
	CStringArray caTracks;
	CStringArray caCountry;
	CStringArray caAdjective;
	int iText;
	int iLaps;
	int iLen;
	
	byte bNewLaps;
	short int iNewLen;
	CString cNewAdj;
	CString cNewTrack;
	CString cNewCountry;

	bool ChangeText;

	CNewSetupDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNewSetupDlg)
	enum { IDD = IDD_NEWSETUP_DIALOG };
	CButton	m_PathFrame;
	CButton	m_Next;
	CString	m_Path;
	int		m_Custom;
	int		m_Typical;
	int		m_FullInstall;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewSetupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNewSetupDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnNext();
	afx_msg void OnBack();
	afx_msg void OnTypical();
	afx_msg void OnCustom();
	afx_msg void OnBrowse();
	afx_msg void OnView();
	afx_msg void OnFullInstall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetCheckName();
	void UnCheckAll();
	void WriteLen(CString Gp2File, int iPos);
	void WriteLaps(CString Gp2File, int iPos);
	void WriteGp2Text(CString Gp2File);
	CString GetGp2Version(CString Gp2File);
	void GetGp2Text(CString Gp2File);
	void AddTrackData(int iPos);
	CString RegGetValue(CString cKey,CString cValue);
	void RegSaveValue(CString cKey,CString cValue,CString cData);
	CString BrowseForFolders(CString cTitle);
	void CreateDir(CString cDir);
	void UnPackFiles();
	void ConvertFile(CString cFileName,bool bDelete);
	CString GetFileName(CString cFileName);
	CString CreateTempDir();
	void DeleteTempDir(CString cDir);
	void ShowGp2Form();
	bool CheckGp2Form();
	void Show2(bool Show);
	void Show1(bool Show);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWSETUPDLG_H__9D17ECA6_D0C2_11D3_999B_0008C7636E27__INCLUDED_)
