#if !defined(AFX_TEAMFINANCE_H__4CE8A835_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_TEAMFINANCE_H__4CE8A835_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TeamFinance.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeamFinance form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTeamFinance : public CFormView
{
public:
	CTeamFinance();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTeamFinance)

// Form Data
public:
	//{{AFX_DATA(CTeamFinance)
	enum { IDD = IDD_TEAMFINANCE };
	CSpinButtonCtrl	m_Spin_WindTunnel;
	CSpinButtonCtrl	m_Spin_WorkShop;
	CSpinButtonCtrl	m_Spin_TestRig;
	CSpinButtonCtrl	m_Spin_SuperComputer;
	CSpinButtonCtrl	m_Spin_Factory;
	CSpinButtonCtrl	m_Spin_Cam;
	CSpinButtonCtrl	m_Spin_Cad;
	CSpinButtonCtrl	m_Spin_Balance;
	int		m_Cad;
	int		m_Factory;
	int		m_Cam;
	int		m_SuperComputer;
	int		m_TestRig;
	int		m_WindTunnel;
	int		m_WorkShop;
	int		m_Balance;
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
	//{{AFX_VIRTUAL(CTeamFinance)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTeamFinance();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTeamFinance)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEAMFINANCE_H__4CE8A835_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
