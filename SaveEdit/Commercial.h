#if !defined(AFX_COMMERCIAL_H__E85C70A0_6C76_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_COMMERCIAL_H__E85C70A0_6C76_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Commercial.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommercial form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CCommercial : public CFormView
{
protected:
	CCommercial();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCommercial)

// Form Data
public:
	//{{AFX_DATA(CCommercial)
	enum { IDD = IDD_MAN_COMMERCIAL };
	CSpinButtonCtrl	m_Spin_Salary;
	CSpinButtonCtrl	m_Spin_Royalty;
	CSpinButtonCtrl	m_Spin_FinalSeason;
	CSpinButtonCtrl	m_Spin_Age;
	CComboBox	m_Team;
	CSpinButtonCtrl	m_Spin_Ability;
	int		m_Ability;
	int		m_Age;
	int		m_FinalSeason;
	int		m_Royalty;
	int		m_Salary;
	//}}AFX_DATA

// Attributes
public:
	int m_Id;
// Operations
public:
	void SaveCommercial(CString file);
	void SetSpin();
	void FillBox();
	void Load(int id, CString file);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommercial)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCommercial();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCommercial)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMERCIAL_H__E85C70A0_6C76_11D4_8FC7_0008C7636E27__INCLUDED_)
