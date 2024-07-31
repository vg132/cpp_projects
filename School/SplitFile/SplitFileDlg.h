// SplitFileDlg.h : header file
//

#if !defined(AFX_SPLITFILEDLG_H__F72754CA_676C_417F_A207_BA2F3F3A7FAB__INCLUDED_)
#define AFX_SPLITFILEDLG_H__F72754CA_676C_417F_A207_BA2F3F3A7FAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSplitFileDlg dialog

class CSplitFileDlg : public CDialog
{
// Construction
public:
	void SplitFile(CString filename);
	CSplitFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSplitFileDlg)
	enum { IDD = IDD_SPLITFILE_DIALOG };
	CString	m_File;
	UINT	m_StartPos;
	CString	m_Part1;
	CString	m_Part2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSplitFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSelectFile();
	afx_msg void OnButtonSplitFile();
	afx_msg void OnButtonPart1();
	afx_msg void OnButtonPart2();
	afx_msg void OnButtonJoin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITFILEDLG_H__F72754CA_676C_417F_A207_BA2F3F3A7FAB__INCLUDED_)
