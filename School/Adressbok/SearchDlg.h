#if !defined(AFX_SEARCHDLG_H__0E3A9B75_9611_11D5_95CB_00B0D064C66D__INCLUDED_)
#define AFX_SEARCHDLG_H__0E3A9B75_9611_11D5_95CB_00B0D064C66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg dialog

class CSearchDlg : public CDialog
{
// Construction
public:
	CSearchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchDlg)
	enum { IDD = IDD_SEARCH };
	BOOL	m_bFirstName;
	BOOL	m_bAddress;
	BOOL	m_bCity;
	BOOL	m_bLastName;
	BOOL	m_bPhone;
	BOOL	m_bPostNr;
	CString	m_Address;
	CString	m_City;
	CString	m_FirstName;
	CString	m_LastName;
	CString	m_Phone;
	CString	m_PostNr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchDlg)
	afx_msg void OnCheckFirstname();
	afx_msg void OnCheckLastname();
	afx_msg void OnCheckAddress();
	afx_msg void OnCheckPostnr();
	afx_msg void OnCheckCity();
	afx_msg void OnCheckPhone();
	afx_msg void OnButtonCancel();
	afx_msg void OnButtonSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHDLG_H__0E3A9B75_9611_11D5_95CB_00B0D064C66D__INCLUDED_)
