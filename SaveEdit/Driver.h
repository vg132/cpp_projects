#if !defined(AFX_DRIVER_H__4CE8A834_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_DRIVER_H__4CE8A834_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Driver.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDriver form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDriver : public CFormView
{
public:
	CDriver();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDriver)

// Form Data
public:
	//{{AFX_DATA(CDriver)
	enum { IDD = IDD_MAN_DRIVER };
	CComboBox	m_Pos;
	CComboBox	m_Role;
	CSpinButtonCtrl	m_Spin_Wins;
	CSpinButtonCtrl	m_Spin_Wet;
	CSpinButtonCtrl	m_Spin_TotalPoints;
	CSpinButtonCtrl	m_Spin_Stamina;
	CSpinButtonCtrl	m_Spin_Speed;
	CSpinButtonCtrl	m_Spin_Skill;
	CSpinButtonCtrl	m_Spin_Salary;
	CSpinButtonCtrl	m_Spin_Races;
	CSpinButtonCtrl	m_Spin_RaceBonus;
	CSpinButtonCtrl	m_Spin_Pole;
	CSpinButtonCtrl	m_Spin_Points;
	CSpinButtonCtrl	m_Spin_PointFinish;
	CSpinButtonCtrl	m_Spin_Overtaking;
	CSpinButtonCtrl	m_Spin_Morale;
	CSpinButtonCtrl	m_Spin_FastLaps;
	CSpinButtonCtrl	m_Spin_Experiance;
	CSpinButtonCtrl	m_Spin_Concentration;
	CSpinButtonCtrl	m_Spin_CHBonus;
	CSpinButtonCtrl	m_Spin_CH;
	CSpinButtonCtrl	m_Spin_Age;
	CComboBox	m_Team;
	CComboBox	m_Country;
	int		m_Age;
	int		m_CH;
	int		m_Concentration;
	int		m_Experience;
	int		m_FastLaps;
	int		m_Morale;
	int		m_Overtaking;
	int		m_Wins;
	int		m_Wet;
	int		m_TotalPoints;
	int		m_Stamina;
	int		m_Speed;
	int		m_Skill;
	int		m_Salary;
	int		m_Races;
	int		m_RaceBonus;
	int		m_Pole;
	int		m_Points;
	int		m_PointFinish;
	int		m_CHBonus;
	//}}AFX_DATA

// Attributes
public:
	int m_Id;
// Operations
public:
	void SaveDriver(CString file);
	void SetSpin();
	void FillBox();
	void Load(int id, CString file);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriver)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDriver();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDriver)
	afx_msg void OnSelchangeDriverComboRole();
	afx_msg void OnSelchangeDriverComboPos();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVER_H__4CE8A834_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
