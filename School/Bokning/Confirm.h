#if !defined(AFX_CONFIRM_H__3A98D043_A1EB_11D5_95E2_00B0D064C66D__INCLUDED_)
#define AFX_CONFIRM_H__3A98D043_A1EB_11D5_95E2_00B0D064C66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Confirm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConfirm dialog

class CConfirm : public CDialog
{
public:


	CConfirm(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConfirm)
	enum { IDD = IDD_CONFIRM };
	CString	m_BookedBy;
	CString	m_From;
	CString	m_Payment;
	CString	m_Room;
	CString	m_To;
	CString	m_Total;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfirm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConfirm)
	afx_msg void OnButtonCancel();
	afx_msg void OnButtonConfirm();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIRM_H__3A98D043_A1EB_11D5_95E2_00B0D064C66D__INCLUDED_)
