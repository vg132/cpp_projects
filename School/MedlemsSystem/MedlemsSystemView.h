// MedlemsSystemView.h : interface of the CMedlemsSystemView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEDLEMSSYSTEMVIEW_H__CF5A93E4_311A_4D1C_A7E6_28901A55637C__INCLUDED_)
#define AFX_MEDLEMSSYSTEMVIEW_H__CF5A93E4_311A_4D1C_A7E6_28901A55637C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMedlemsSystemView : public CFormView
{
protected: // create from serialization only
	CMedlemsSystemView();
	DECLARE_DYNCREATE(CMedlemsSystemView)

public:
	//{{AFX_DATA(CMedlemsSystemView)
	enum{ IDD = IDD_MEDLEMSSYSTEM_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CMedlemsSystemDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMedlemsSystemView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMedlemsSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMedlemsSystemView)
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MedlemsSystemView.cpp
inline CMedlemsSystemDoc* CMedlemsSystemView::GetDocument()
   { return (CMedlemsSystemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDLEMSSYSTEMVIEW_H__CF5A93E4_311A_4D1C_A7E6_28901A55637C__INCLUDED_)
