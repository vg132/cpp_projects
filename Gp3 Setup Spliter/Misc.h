#if !defined(AFX_MISC_H__11D0E39A_C233_4CBB_9220_ED8B73B7B5D0__INCLUDED_)
#define AFX_MISC_H__11D0E39A_C233_4CBB_9220_ED8B73B7B5D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Misc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMisc dialog

#include "SetupFile.h"

class CMisc : public CPropertyPage
{
	DECLARE_DYNCREATE(CMisc)

// Construction
public:
	void SaveSetup();
	void SetGpXSetupFile(CSetupFile *Setup,int id);
	void EnableControls(bool enable);
	CMisc();
	~CMisc();
private:
	void UpdateBrakeBalance();
	bool LoadSetup();
	void InitControls();

	CSetupFile *m_SetupFile;
	int m_Id;
// Dialog Data
	//{{AFX_DATA(CMisc)
	enum { IDD = IDD_MISC };
	CSliderCtrl	m_SliderBrakeBalance;
	CSpinButtonCtrl	m_SpinThirdStop;
	CSpinButtonCtrl	m_SpinSecondStop;
	CSpinButtonCtrl	m_SpinFirstStop;
	CSpinButtonCtrl	m_SpinRearWing;
	CSpinButtonCtrl	m_SpinFrontWing;
	CSpinButtonCtrl	m_SpinGear6;
	CSpinButtonCtrl	m_SpinGear5;
	CSpinButtonCtrl	m_SpinGear4;
	CSpinButtonCtrl	m_SpinGear3;
	CSpinButtonCtrl	m_SpinGear1;
	CSpinButtonCtrl	m_SpinGear2;
	int		m_Gear1;
	int		m_Gear2;
	int		m_Gear4;
	int		m_Gear5;
	int		m_Gear6;
	int		m_Gear3;
	int		m_FrontWing;
	int		m_RearWing;
	int		m_FirstStop;
	int		m_SecondStop;
	int		m_ThirdStop;
	CString	m_BrakeBalance;
	int		m_RadioNone;
	int		m_RadioOne;
	int		m_RadioTwo;
	int		m_RadioThree;
	int		m_Differential;
	int		m_TyreChoice;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMisc)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CMisc)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRadioPitstopNone();
	afx_msg void OnRadioPitstopOneStop();
	afx_msg void OnRadioPitstopThreeStops();
	afx_msg void OnRadioPitstopTwoStops();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MISC_H__11D0E39A_C233_4CBB_9220_ED8B73B7B5D0__INCLUDED_)
