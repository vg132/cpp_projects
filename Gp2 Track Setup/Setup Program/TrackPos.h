#if !defined(AFX_TRACKPOS_H__1A1D7320_D431_11D3_999B_0008C7636E27__INCLUDED_)
#define AFX_TRACKPOS_H__1A1D7320_D431_11D3_999B_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TrackPos.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TrackPos dialog

class TrackPos : public CDialog
{
// Construction
public:
	TrackPos(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TrackPos)
	enum { IDD = IDD_TrackPos };
	CString	m_TrackPos;
	BOOL	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TrackPos)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TrackPos)
	afx_msg void OnNext();
	afx_msg void OnExit();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACKPOS_H__1A1D7320_D431_11D3_999B_0008C7636E27__INCLUDED_)
