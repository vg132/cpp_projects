// Uppgift2Dlg.h : header file
//

#if !defined(AFX_UPPGIFT2DLG_H__B6D99627_9ADA_11D5_95D4_00B0D064C66D__INCLUDED_)
#define AFX_UPPGIFT2DLG_H__B6D99627_9ADA_11D5_95D4_00B0D064C66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUppgift2Dlg dialog

#include "ViperString.h"

class CUppgift2Dlg : public CDialog
{
private:
	CViperString vs;
public:
	CUppgift2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUppgift2Dlg)
	enum { IDD = IDD_UPPGIFT2_DIALOG };
	CString	m_Add1;
	CString	m_Add2;
	CString	m_Add3;
	CString	m_Equals;
	CString	m_Find;
	CString	m_Replace;
	CString	m_Result;
	CString	m_Real;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUppgift2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUppgift2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonEquals();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonAdd2();
	afx_msg void OnButtonReplace();
	afx_msg void OnButtonUppercase();
	afx_msg void OnButtonLowercase();
	afx_msg void OnSetfocusEditReal();
	afx_msg void OnSetfocusEditResult();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPPGIFT2DLG_H__B6D99627_9ADA_11D5_95D4_00B0D064C66D__INCLUDED_)
