// BokningDoc.h : interface of the CBokningDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOKNINGDOC_H__42E2D2B1_6275_48ED_887A_C8E1A0550498__INCLUDED_)
#define AFX_BOKNINGDOC_H__42E2D2B1_6275_48ED_887A_C8E1A0550498__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBokningDoc : public CDocument
{
protected: // create from serialization only
	CBokningDoc();
	DECLARE_DYNCREATE(CBokningDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBokningDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBokningDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBokningDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOKNINGDOC_H__42E2D2B1_6275_48ED_887A_C8E1A0550498__INCLUDED_)
