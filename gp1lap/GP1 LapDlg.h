// GP1 LapDlg.h : header file
//

#if !defined(AFX_GP1LAPDLG_H__3A0AF5A8_BB9E_11D3_999B_0008C7636E27__INCLUDED_)
#define AFX_GP1LAPDLG_H__3A0AF5A8_BB9E_11D3_999B_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGP1LapDlg dialog

class CGP1LapDlg : public CDialog
{
// Construction
public:
	CGP1LapDlg(CWnd* pParent = NULL);	// standard constructor
	//Path variable
	char m_Path[MAX_PATH];
	//Track Dir
	CString m_TrackPath;
// Dialog Data
	//{{AFX_DATA(CGP1LapDlg)
	enum { IDD = IDD_GP1LAP_DIALOG };
	CButton	m_Test;
	int		m_Laps;
	CString	m_FileName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGP1LapDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGP1LapDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnExport();
	afx_msg void OnImport();
	afx_msg void OnAbout();
	afx_msg void OnExit();
	afx_msg void OnTrackDir();
	afx_msg void GetTrackDir();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GP1LAPDLG_H__3A0AF5A8_BB9E_11D3_999B_0008C7636E27__INCLUDED_)
