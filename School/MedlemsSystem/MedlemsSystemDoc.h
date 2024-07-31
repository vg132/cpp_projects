// MedlemsSystemDoc.h : interface of the CMedlemsSystemDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEDLEMSSYSTEMDOC_H__6240EC58_6076_4BD1_A91F_2BE97AA48175__INCLUDED_)
#define AFX_MEDLEMSSYSTEMDOC_H__6240EC58_6076_4BD1_A91F_2BE97AA48175__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMedlemsSystemDoc : public CDocument
{
protected: // create from serialization only
	CMedlemsSystemDoc();
	DECLARE_DYNCREATE(CMedlemsSystemDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMedlemsSystemDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMedlemsSystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMedlemsSystemDoc)
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDLEMSSYSTEMDOC_H__6240EC58_6076_4BD1_A91F_2BE97AA48175__INCLUDED_)
