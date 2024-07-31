// AdressbokDlg.h : header file
//

#if !defined(AFX_ADRESSBOKDLG_H__336B1A2B_956B_11D5_95CA_00B0D064C66D__INCLUDED_)
#define AFX_ADRESSBOKDLG_H__336B1A2B_956B_11D5_95CA_00B0D064C66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAdressbokDlg dialog

#include "Telefonbok.h"
#include "Person.h"
#include "SearchDlg.h"

class CAdressbokDlg : public CDialog
{
private:
	void UpdateListView(bool ViewAll=true);
	Telefonbok telefonbok;
	Person* person;
	int curitem;
	CImageList m_SmallImageList;
public:
	void EnableControls(bool enable);

	CAdressbokDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAdressbokDlg)
	enum { IDD = IDD_ADRESSBOK_DIALOG };
	CButton	m_Save;
	CListCtrl	m_ContactList;
	CString	m_Address;
	CString	m_City;
	CString	m_LastName;
	CString	m_FirstName;
	CString	m_Phone;
	CString	m_PostNr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdressbokDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAdressbokDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileSave();
	afx_msg void OnAppAbout();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonRemove();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonSearch();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSparasom();
	afx_msg void OnClickContactList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonShowall();
	afx_msg void OnFileNy();
	afx_msg void OnFileClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADRESSBOKDLG_H__336B1A2B_956B_11D5_95CA_00B0D064C66D__INCLUDED_)

