#if !defined(AFX_WORKMECH_H__5A697A0C_6ECD_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_WORKMECH_H__5A697A0C_6ECD_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkMech.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWorkMech form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CWorkMech : public CFormView
{
protected:
	CWorkMech();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CWorkMech)

// Form Data
public:
	//{{AFX_DATA(CWorkMech)
	enum { IDD = IDD_WORK_MECH };
	CSpinButtonCtrl	m_Spin_Car1Damage;
	CSpinButtonCtrl	m_Spin_Car1Ware;
	CSpinButtonCtrl	m_Spin_Car2Damage;
	CSpinButtonCtrl	m_Spin_Car2Ware;
	CSpinButtonCtrl	m_Spin_Car3Damage;
	CSpinButtonCtrl	m_Spin_Car3Ware;
	CSpinButtonCtrl	m_Spin_Car4Damage;
	CSpinButtonCtrl	m_Spin_Car4Ware;
	CSpinButtonCtrl	m_Spin_Cost_Mile;
	CSpinButtonCtrl	m_Spin_FreePractice;
	CSpinButtonCtrl	m_Spin_Miles;
	CSpinButtonCtrl	m_Spin_Spares;
	int		m_Car1Damage;
	int		m_Car1Ware;
	int		m_Car2Damage;
	int		m_Car2Ware;
	int		m_Car3Damage;
	int		m_Car3Ware;
	int		m_Car4Damage;
	int		m_Car4Ware;
	int		m_FreePractice;
	int		m_Spares;
	int		m_Miles;
	int		m_Cost_Mile;
	//}}AFX_DATA

// Attributes
public:

	int m_Id;
// Operations
public:
	void Save(CString file);
	void SetSpin();
	void Load(int id, CString file);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkMech)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWorkMech();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CWorkMech)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKMECH_H__5A697A0C_6ECD_11D4_8FC7_0008C7636E27__INCLUDED_)
