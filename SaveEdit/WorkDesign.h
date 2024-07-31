#if !defined(AFX_WORKDESIGN_H__10448CE5_6F03_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_WORKDESIGN_H__10448CE5_6F03_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkDesign.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWorkDesign form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CWorkDesign : public CFormView
{
protected:
	CWorkDesign();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CWorkDesign)

// Form Data
public:
	//{{AFX_DATA(CWorkDesign)
	enum { IDD = IDD_WORK_DESIGN };
	CSpinButtonCtrl	m_Spin_Reliability_Electronics;
	CSpinButtonCtrl	m_Spin_Reliability_Hydraulics;
	CSpinButtonCtrl	m_Spin_Reliability_Suspension;
	CSpinButtonCtrl	m_Spin_Reliability_Throttle;
	CSpinButtonCtrl	m_Spin_Reliability_Gearbox;
	CSpinButtonCtrl	m_Spin_Reliability_Clutch;
	CSpinButtonCtrl	m_Spin_Reliability_Breakes;
	CSpinButtonCtrl	m_Spin_Performence_Throttle;
	CSpinButtonCtrl	m_Spin_Performence_Suspension;
	CSpinButtonCtrl	m_Spin_Performence_Hydraulics;
	CSpinButtonCtrl	m_Spin_Performence_Gearbox;
	CSpinButtonCtrl	m_Spin_Performence_Electronics;
	CSpinButtonCtrl	m_Spin_Performence_Clutch;
	CSpinButtonCtrl	m_Spin_Performence_Breakes;
	CSpinButtonCtrl	m_Spin_ActiveSuspension;
	CSpinButtonCtrl	m_Spin_AutomaticGears;
	CSpinButtonCtrl	m_Spin_Powerbreakes;
	CSpinButtonCtrl	m_Spin_Tractioncontrol;
	int		m_ActiveSuspension;
	int		m_AutomaticGears;
	int		m_PowerBreakes;
	int		m_TractionControl;
	int		m_Performence_Breakes;
	int		m_Performence_Clutch;
	int		m_Performence_Electronics;
	int		m_Performence_Gearbox;
	int		m_Performence_Hydraulics;
	int		m_Performence_Suspension;
	int		m_Performence_Throttle;
	int		m_Reliability_Clutch;
	int		m_Reliability_Electronics;
	int		m_Reliability_Gearbox;
	int		m_Reliability_Hydraulics;
	int		m_Reliability_Suspension;
	int		m_Reliability_Breakes;
	int		m_Reliability_Throttle;
	//}}AFX_DATA

// Attributes
public:

	int m_Id;
// Operations
public:
	void SetSpin();
	void Save(CString file);
	void Load(int id, CString file);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkDesign)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWorkDesign();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CWorkDesign)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKDESIGN_H__10448CE5_6F03_11D4_8FC7_0008C7636E27__INCLUDED_)
