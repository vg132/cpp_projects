#if !defined(AFX_DEPCOMMERCIAL_H__66D61720_6E51_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_DEPCOMMERCIAL_H__66D61720_6E51_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DepCommercial.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepCommercial form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDepCommercial : public CFormView
{
protected:
	CDepCommercial();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDepCommercial)

// Form Data
public:
	//{{AFX_DATA(CDepCommercial)
	enum { IDD = IDD_DEP_COMMERCIAL };
	CSpinButtonCtrl	m_Spin_Stars_VeryGood;
	CSpinButtonCtrl	m_Spin_Stars_Trainee;
	CSpinButtonCtrl	m_Spin_Stars_Excellent;
	CSpinButtonCtrl	m_Spin_Stars_Good;
	CSpinButtonCtrl	m_Spin_Stars_Average;
	CSpinButtonCtrl	m_Spin_Standard_VeryGood;
	CSpinButtonCtrl	m_Spin_Standard_Trainee;
	CSpinButtonCtrl	m_Spin_Standard_Good;
	CSpinButtonCtrl	m_Spin_Standard_Excellent;
	CSpinButtonCtrl	m_Spin_Standard_Average;
	CSpinButtonCtrl	m_Spin_Morale;
	CSpinButtonCtrl	m_Spin_Available;
	int		m_Available;
	int		m_Morale;
	int		m_Standard_Average;
	int		m_Standard_Excellent;
	int		m_Standard_Good;
	int		m_Standard_Trainee;
	int		m_Standard_VeryGood;
	int		m_Stars_Average;
	int		m_Stars_Excellent;
	int		m_Stars_Good;
	int		m_Stars_Trainee;
	int		m_Stars_VeryGood;
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
	//{{AFX_VIRTUAL(CDepCommercial)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDepCommercial();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDepCommercial)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPCOMMERCIAL_H__66D61720_6E51_11D4_8FC7_0008C7636E27__INCLUDED_)
