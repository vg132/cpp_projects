#if !defined(AFX_MATCHINGDLG_H__15F6C6D5_A101_11D5_95DF_00B0D064C66D__INCLUDED_)
#define AFX_MATCHINGDLG_H__15F6C6D5_A101_11D5_95DF_00B0D064C66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MatchingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMatchingDlg dialog

#include "Person.h"
#include "List.h"
#include "Id.h"

class CMatchingDlg : public CDialog
{
private:
	CId* m_Id;
	CPerson* m_Person;
	List<CPerson>* m_ListPersons;
public:
	int m_Selected;
	void SetMatchingList(List<CPerson>* matching);
	CMatchingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMatchingDlg)
	enum { IDD = IDD_MATCHING_PERSONS };
	CListCtrl	m_Persons;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMatchingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMatchingDlg)
	afx_msg void OnDblclkListPersons(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATCHINGDLG_H__15F6C6D5_A101_11D5_95DF_00B0D064C66D__INCLUDED_)
