#if !defined(AFX_TRACKINFO_H__0E9ECFC0_D72F_11D3_999B_0008C7636E27__INCLUDED_)
#define AFX_TRACKINFO_H__0E9ECFC0_D72F_11D3_999B_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TrackInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TrackInfo dialog

class TrackInfo : public CDialog
{
// Construction
public:
	TrackInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TrackInfo)
	enum { IDD = IDD_TrackInfo };
	CString	m_Adj;
	CString	m_Country;
	CString	m_Laps;
	CString	m_Len;
	CString	m_Name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TrackInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TrackInfo)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACKINFO_H__0E9ECFC0_D72F_11D3_999B_0008C7636E27__INCLUDED_)
