// SaveEditDoc.h : interface of the CSaveEditDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAVEEDITDOC_H__4CE8A82A_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_SAVEEDITDOC_H__4CE8A82A_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSaveEditDoc : public CDocument
{
protected: // create from serialization only
	CSaveEditDoc();
	DECLARE_DYNCREATE(CSaveEditDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaveEditDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSaveEditDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSaveEditDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVEEDITDOC_H__4CE8A82A_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
