#if !defined(AFX_FRONT_H__69605EC3_1876_4F71_BC13_313B68D14732__INCLUDED_)
#define AFX_FRONT_H__69605EC3_1876_4F71_BC13_313B68D14732__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Front.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFront dialog

#include "SetupFile.h"

class CFront : public CPropertyPage
{
	DECLARE_DYNCREATE(CFront)

// Construction
public:
	void SaveSetup();
	void SetGpXSetupFile(CSetupFile *Setup, int id);
	void EnableControls(bool enable);
	CFront();
	~CFront();
private:
	void UpdateRideHeight();
	void InitControls();
	bool LoadSetup();
	CSetupFile *m_SetupFile;
	int m_Id;
// Dialog Data
	//{{AFX_DATA(CFront)
	enum { IDD = IDD_FRONT };
	CSliderCtrl	m_SliderRightRideHeight;
	CSliderCtrl	m_SliderLeftRideHeight;
	CSpinButtonCtrl	m_SpinRightSlowRebound;
	CSpinButtonCtrl	m_SpinRightSlowBump;
	CSpinButtonCtrl	m_SpinRightPackers;
	CSpinButtonCtrl	m_SpinRightFastRebound;
	CSpinButtonCtrl	m_SpinRightDumper;
	CSpinButtonCtrl	m_SpinLeftSlowRebound;
	CSpinButtonCtrl	m_SpinLeftSlowBump;
	CSpinButtonCtrl	m_SpinLeftPackers;
	CSpinButtonCtrl	m_SpinLeftFastRebound;
	CSpinButtonCtrl	m_SpinLeftDumper;
	int		m_AntiRollBar;
	int		m_LeftSpring;
	int		m_RightSpring;
	int		m_LeftDumper;
	int		m_LeftFastRebound;
	int		m_LeftPackers;
	int		m_LeftSlowBump;
	int		m_LeftSlowRebound;
	int		m_RightDumper;
	int		m_RightFastRebound;
	int		m_RightPackers;
	int		m_RightSlowBump;
	int		m_RightSlowRebound;
	CString	m_LeftRideHeight;
	CString	m_RightRideHeight;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CFront)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CFront)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRONT_H__69605EC3_1876_4F71_BC13_313B68D14732__INCLUDED_)
