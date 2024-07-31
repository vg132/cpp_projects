#if !defined(AFX_SETTINGS_H__3645C88C_C9A5_4809_A9F4_7AF5078CC7E2__INCLUDED_)
#define AFX_SETTINGS_H__3645C88C_C9A5_4809_A9F4_7AF5078CC7E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Settings.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettings dialog

#define WM_NEWPLAYER WM_APP+0x600

class CSettings : public CPropertyPage
{
	DECLARE_DYNCREATE(CSettings)
private:
	CWnd *m_pParentWnd;
	UINT m_Msg;
// Construction
public:
	void Init(CWnd *pParentWnd,UINT msg);
	CString GetPlayer();
	void SetPlayer(CString player);
	CSettings();
	~CSettings();

// Dialog Data
	//{{AFX_DATA(CSettings)
	enum { IDD = IDD_SETTINGS };
	CString	m_Mp3Player;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSettings)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSettings)
	afx_msg void OnBrowseMp3player();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGS_H__3645C88C_C9A5_4809_A9F4_7AF5078CC7E2__INCLUDED_)
