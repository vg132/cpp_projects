#if !defined(AFX_SPONSOR_H__814D5980_6D23_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_SPONSOR_H__814D5980_6D23_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Sponsor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSponsor form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CSponsor : public CFormView
{
protected:
	CSponsor();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSponsor)

// Form Data
public:
	//{{AFX_DATA(CSponsor)
	enum { IDD = IDD_SPONSORS };
	CComboBox	m_Tyre;
	CComboBox	m_Fuel;
	CComboBox	m_Team;
	CComboBox	m_Engine;
	CComboBox	m_Cash6;
	CComboBox	m_Cash5;
	CComboBox	m_Cash4;
	CComboBox	m_Cash3;
	CComboBox	m_Cash2;
	CComboBox	m_Cash1;
	CSpinButtonCtrl	m_Spin_Value9;
	CSpinButtonCtrl	m_Spin_Value8;
	CSpinButtonCtrl	m_Spin_Value7;
	CSpinButtonCtrl	m_Spin_Value6;
	CSpinButtonCtrl	m_Spin_Value5;
	CSpinButtonCtrl	m_Spin_Value4;
	CSpinButtonCtrl	m_Spin_Value3;
	CSpinButtonCtrl	m_Spin_Value2;
	CSpinButtonCtrl	m_Spin_Value10;
	CSpinButtonCtrl	m_Spin_Value1;
	int		m_Value1;
	int		m_Value10;
	int		m_Value2;
	int		m_Value3;
	int		m_Value6;
	int		m_Value4;
	int		m_Value5;
	int		m_Value7;
	int		m_Value8;
	int		m_Value9;
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
	//{{AFX_VIRTUAL(CSponsor)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSponsor();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CSponsor)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPONSOR_H__814D5980_6D23_11D4_8FC7_0008C7636E27__INCLUDED_)
