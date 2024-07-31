#if !defined(AFX_DESIGN_H__E85C70A1_6C76_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_DESIGN_H__E85C70A1_6C76_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Design.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDesign form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDesign : public CFormView
{
protected:
	CDesign();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDesign)

// Form Data
public:
	//{{AFX_DATA(CDesign)
	enum { IDD = IDD_MAN_DESIGN };
	CSpinButtonCtrl	m_Spin_FinalSeason;
	CSpinButtonCtrl	m_Spin_CHBonus;
	CSpinButtonCtrl	m_Spin_Ability;
	CSpinButtonCtrl	m_Spin_Age;
	CSpinButtonCtrl	m_Spin_RaceBonus;
	CSpinButtonCtrl	m_Spin_Salary;
	CComboBox	m_Team;
	CComboBox	m_DriverLoyalty;
	int		m_CHBonus;
	int		m_Ability;
	int		m_Salary;
	int		m_Age;
	int		m_FinalSeason;
	int		m_RaceBonus;
	//}}AFX_DATA

// Attributes
public:

	int m_Id;
// Operations
public:
	void Save(CString file);
	void SetSpin();
	void FillBox();
	void Load(int id, CString file);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesign)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDesign();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDesign)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESIGN_H__E85C70A1_6C76_11D4_8FC7_0008C7636E27__INCLUDED_)
