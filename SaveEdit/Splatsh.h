#if !defined(AFX_SPLATSH_H__41072147_7083_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_SPLATSH_H__41072147_7083_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Splatsh.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplatsh dialog

class CSplatsh : public CDialog
{
// Construction
public:
	CSplatsh(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSplatsh)
	enum { IDD = IDD_SPLATSH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplatsh)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSplatsh)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLATSH_H__41072147_7083_11D4_8FC7_0008C7636E27__INCLUDED_)
