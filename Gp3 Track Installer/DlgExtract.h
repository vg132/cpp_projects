#if !defined(AFX_DLGEXTRACT_H__6A7043DA_AC0B_4CB5_9482_D2A7C314654E__INCLUDED_)
#define AFX_DLGEXTRACT_H__6A7043DA_AC0B_4CB5_9482_D2A7C314654E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgExtract.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgExtract dialog

class CDlgExtract : public CDialog
{
// Construction
public:
	CDlgExtract(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgExtract)
	enum { IDD = IDD_DIALOG_EXTRACT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgExtract)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgExtract)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEXTRACT_H__6A7043DA_AC0B_4CB5_9482_D2A7C314654E__INCLUDED_)
