#if !defined(AFX_REAR_H__8A1A6FAD_7DFB_483C_8B39_904C6D0BBCD2__INCLUDED_)
#define AFX_REAR_H__8A1A6FAD_7DFB_483C_8B39_904C6D0BBCD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Rear.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRear dialog

#include "SetupFile.h"

class CRear : public CPropertyPage
{
	DECLARE_DYNCREATE(CRear)

// Construction
public:
	void SaveSetup();
	void UpdateRideHeight();
	void SetGpXSetupFile(CSetupFile *Setup,int id);
	void EnableControls(bool enable);
	CRear();
	~CRear();

private:
	void InitControls();
	bool LoadSetup();
	CSetupFile *m_SetupFile;
	int m_Id;
// Dialog Data
	//{{AFX_DATA(CRear)
	enum { IDD = IDD_REAR };
	CSliderCtrl	m_SliderLeftRideHeight;
	CSliderCtrl	m_SliderRightRideHeight;
	CSpinButtonCtrl	m_SpinLeftDumper;
	CSpinButtonCtrl	m_SpinLeftFastRebound;
	CSpinButtonCtrl	m_SpinLeftPackers;
	CSpinButtonCtrl	m_SpinLeftSlowBump;
	CSpinButtonCtrl	m_SpinLeftSlowRebound;
	CSpinButtonCtrl	m_SpinRightDumper;
	CSpinButtonCtrl	m_SpinRightFastRebound;
	CSpinButtonCtrl	m_SpinRightPackers;
	CSpinButtonCtrl	m_SpinRightSlowBump;
	CSpinButtonCtrl	m_SpinRightSlowRebound;
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
	//{{AFX_VIRTUAL(CRear)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CRear)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REAR_H__8A1A6FAD_7DFB_483C_8B39_904C6D0BBCD2__INCLUDED_)
