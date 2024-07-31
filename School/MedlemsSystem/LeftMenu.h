#if !defined(AFX_LEFTMENU_H__7EE6BC3A_435A_43C3_9CD9_9132937A12D9__INCLUDED_)
#define AFX_LEFTMENU_H__7EE6BC3A_435A_43C3_9CD9_9132937A12D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftMenu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftMenu form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "Member.h"
#include "List.h"

class CLeftMenu : public CFormView
{
protected:
	CLeftMenu();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftMenu)

// Form Data
public:
	//{{AFX_DATA(CLeftMenu)
	enum { IDD = IDD_MENU };
	CTreeCtrl	m_Tree;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	void MakeImageList();
	void BuildTree();
	HTREEITEM BuildNode(LPSTR szText, int Image, int SelectedImage, int id, HTREEITEM Parant);
	CImageList *m_pImageList;
	CMember *m;
	List<CMember> l;
	CMainFrame* m_MainFrame;
	int m_CurSelected;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftMenu)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftMenu();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLeftMenu)
	afx_msg void OnSelchangedContact(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTMENU_H__7EE6BC3A_435A_43C3_9CD9_9132937A12D9__INCLUDED_)
