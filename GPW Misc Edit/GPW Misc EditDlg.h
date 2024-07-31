// GPW Misc EditDlg.h : header file
//

#if !defined(AFX_GPWMISCEDITDLG_H__F819065A_81AA_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_GPWMISCEDITDLG_H__F819065A_81AA_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGPWMiscEditDlg dialog

#include "Common.h"

class CGPWMiscEditDlg : public CDialog
{
// Construction
public:
	void SetSpin();
	CGPWMiscEditDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGPWMiscEditDlg)
	enum { IDD = IDD_GPWMISCEDIT_DIALOG };
	CSpinButtonCtrl	m_Spin9;
	CSpinButtonCtrl	m_Spin7;
	CSpinButtonCtrl	m_Spin8;
	CSpinButtonCtrl	m_Spin5;
	CSpinButtonCtrl	m_Spin6;
	CSpinButtonCtrl	m_Spin30;
	CSpinButtonCtrl	m_Spin4;
	CSpinButtonCtrl	m_Spin29;
	CSpinButtonCtrl	m_Spin28;
	CSpinButtonCtrl	m_Spin26;
	CSpinButtonCtrl	m_Spin27;
	CSpinButtonCtrl	m_Spin3;
	CSpinButtonCtrl	m_Spin25;
	CSpinButtonCtrl	m_Spin24;
	CSpinButtonCtrl	m_Spin23;
	CSpinButtonCtrl	m_Spin22;
	CSpinButtonCtrl	m_Spin21;
	CSpinButtonCtrl	m_Spin20;
	CSpinButtonCtrl	m_Spin2;
	CSpinButtonCtrl	m_Spin19;
	CSpinButtonCtrl	m_Spin18;
	CSpinButtonCtrl	m_Spin17;
	CSpinButtonCtrl	m_Spin16;
	CSpinButtonCtrl	m_Spin15;
	CSpinButtonCtrl	m_Spin14;
	CSpinButtonCtrl	m_Spin13;
	CSpinButtonCtrl	m_Spin12;
	CSpinButtonCtrl	m_Spin11;
	CSpinButtonCtrl	m_Spin10;
	CSpinButtonCtrl	m_Spin1;
	int		m_Staff1;
	int		m_Staff2;
	int		m_Staff3;
	int		m_Staff4;
	int		m_Staff5;
	int		m_Factory1;
	int		m_Factory2;
	int		m_Factory4;
	int		m_Factory3;
	int		m_Factory5;
	int		m_Commercial_Average;
	int		m_Commercial_Excellent;
	int		m_Commercial_Good;
	int		m_Commercial_Trainee;
	int		m_Commercial_VeryGood;
	int		m_Design_Average;
	int		m_Design_Excellent;
	int		m_Design_Good;
	int		m_Design_Trainee;
	int		m_Design_VeryGood;
	int		m_Engineering_Average;
	int		m_Engineering_VeryGood;
	int		m_Engineering_Trainee;
	int		m_Engineering_Good;
	int		m_Engineering_Excellent;
	int		m_Mechanics_VeryGood;
	int		m_Mechanics_Trainee;
	int		m_Mechanics_Good;
	int		m_Mechanics_Excellent;
	int		m_Mechanics_Average;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGPWMiscEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CCommon m_Common;
	CString m_Path;
	// Generated message map functions
	//{{AFX_MSG(CGPWMiscEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnEditGpwdirectory();
	afx_msg void OnFileImport();
	afx_msg void OnFileExport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPWMISCEDITDLG_H__F819065A_81AA_11D4_8FC7_0008C7636E27__INCLUDED_)
