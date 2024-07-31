#if !defined(AFX_LICENSING_H__542A33C0_6EA8_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_LICENSING_H__542A33C0_6EA8_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Licensing.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLicensing form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CLicensing : public CFormView
{
protected:
	CLicensing();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLicensing)

// Form Data
public:
	//{{AFX_DATA(CLicensing)
	enum { IDD = IDD_LICENSING };
	CSpinButtonCtrl	m_Spin_Completion_Publishing;
	CSpinButtonCtrl	m_Spin_Completion_VideoGames;
	CSpinButtonCtrl	m_Spin_Completion_FanClub;
	CSpinButtonCtrl	m_Spin_Completion_Clothing;
	CSpinButtonCtrl	m_Spin_Completion_Chronometers;
	CSpinButtonCtrl	m_Spin_Completion_Cars;
	CSpinButtonCtrl	m_Spin_Demand_Publishing;
	CSpinButtonCtrl	m_Spin_Demand_Clothing;
	CSpinButtonCtrl	m_Spin_Demand_Chronometers;
	CSpinButtonCtrl	m_Spin_Demand_Cars;
	CSpinButtonCtrl	m_Spin_Demand_FanClub;
	CSpinButtonCtrl	m_Spin_Demand_VideoGames;
	CSpinButtonCtrl	m_Spin_Cash_VideoGames;
	CSpinButtonCtrl	m_Spin_Cash_Publishing;
	CSpinButtonCtrl	m_Spin_Cash_FanClub;
	CSpinButtonCtrl	m_Spin_Cash_Clothing;
	CSpinButtonCtrl	m_Spin_Cash_Chronometers;
	CSpinButtonCtrl	m_Spin_Cash_Cars;
	BOOL	m_Check_Cars;
	BOOL	m_Check_Clothing;
	BOOL	m_Check_FanClub;
	BOOL	m_Check_Publishing;
	BOOL	m_Check_VideoGames;
	int		m_Cash_Cars;
	int		m_Cash_Chronometers;
	int		m_Cash_Clothing;
	int		m_Cash_FanClub;
	int		m_Cash_Publishing;
	int		m_Cash_VideoGames;
	int		m_Completion_Cars;
	int		m_Completion_Publishing;
	int		m_Completion_VideoGames;
	int		m_Completion_Chronometers;
	int		m_Completion_Clothing;
	int		m_Completion_FanClub;
	int		m_Demand_Cars;
	int		m_Demand_FanClub;
	int		m_Demand_Publishing;
	int		m_Demand_VideoGams;
	int		m_Demand_Clothing;
	int		m_Demand_Chronometers;
	BOOL	m_Check_Chronometers;
	//}}AFX_DATA

// Attributes
public:

	int m_Id;
// Operations
public:
	void Save(CString file);
	void SetSpin();
	int ConvertCompletion(bool togpw,int Completion);
	void Load(int id, CString file);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLicensing)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLicensing();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLicensing)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LICENSING_H__542A33C0_6EA8_11D4_8FC7_0008C7636E27__INCLUDED_)
