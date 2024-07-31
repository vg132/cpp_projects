#if !defined(AFX_QUIT_H__9D17ECAE_D0C2_11D3_999B_0008C7636E27__INCLUDED_)
#define AFX_QUIT_H__9D17ECAE_D0C2_11D3_999B_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Quit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuit dialog

class CQuit : public CDialog
{
// Construction
public:
	CQuit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQuit)
	enum { IDD = IDD_Quit };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQuit)
	virtual BOOL OnInitDialog();
	afx_msg void OnExit();
	afx_msg void OnResume();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUIT_H__9D17ECAE_D0C2_11D3_999B_0008C7636E27__INCLUDED_)
