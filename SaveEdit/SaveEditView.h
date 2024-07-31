// SaveEditView.h : interface of the CSaveEditView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAVEEDITVIEW_H__4CE8A82C_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_SAVEEDITVIEW_H__4CE8A82C_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LoadText.h"
#include "MainFrm.h"

class CSaveEditView : public CFormView
{
public: // create from serialization only
	CSaveEditView();
	DECLARE_DYNCREATE(CSaveEditView)

public:
	//{{AFX_DATA(CSaveEditView)
	enum { IDD = IDD_SAVEEDIT_FORM };
	CTreeCtrl	m_Tree;
	//}}AFX_DATA

// Attributes
public:
	CSaveEditDoc* GetDocument();
	int m_Close;
// Operations
public:
	int m_WorkTeam[139];
	int m_Team;
	CLoadText m_Text;
	CString m_DataFile;
	CImageList* m_pImageList;
	int iCurShow;
	
	CMainFrame* m_MainFrame;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaveEditView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	void CloseFile();
	void GetTeam(CString file);
	void BuildTree(CString file);
	void EnableTree(BOOL enable);
	HTREEITEM BuildNode(LPSTR szText,int Image, int SelectedImage, int id, HTREEITEM Parant);
	virtual ~CSaveEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSaveEditView)
	afx_msg void OnSelchangedNavTree(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SaveEditView.cpp
inline CSaveEditDoc* CSaveEditView::GetDocument()
   { return (CSaveEditDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVEEDITVIEW_H__4CE8A82C_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
