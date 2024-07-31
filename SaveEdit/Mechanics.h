#if !defined(AFX_MECHANICS_H__E85C70A3_6C76_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_MECHANICS_H__E85C70A3_6C76_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mechanics.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMechanics form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMechanics : public CFormView
{
protected:
	CMechanics();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMechanics)

// Form Data
public:
	//{{AFX_DATA(CMechanics)
	enum { IDD = IDD_MAN_MECHANICS };
	CSpinButtonCtrl	m_Spin_Salary;
	CSpinButtonCtrl	m_Spin_RaceBonus;
	CSpinButtonCtrl	m_Spin_FinalSeason;
	CSpinButtonCtrl	m_Spin_Age;
	CSpinButtonCtrl	m_Spin_CHBonus;
	CSpinButtonCtrl	m_Spin_Ability;
	CComboBox	m_DriverLoyalty;
	CComboBox	m_Team;
	int		m_CHBonus;
	int		m_Age;
	int		m_Ability;
	int		m_FinalSeason;
	int		m_RaceBonus;
	int		m_Salary;
	//}}AFX_DATA

// Attributes
public:

	int m_Id;
// Operations
public:
	void FillBox();
	void SetSpin();
	void Save(CString file);
	void Load(int id, CString file);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMechanics)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMechanics();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMechanics)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MECHANICS_H__E85C70A3_6C76_11D4_8FC7_0008C7636E27__INCLUDED_)
