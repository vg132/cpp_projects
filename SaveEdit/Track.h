#if !defined(AFX_TRACK_H__EA937180_6C4D_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_TRACK_H__EA937180_6C4D_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Track.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTrack form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTrack : public CFormView
{
protected:
	CTrack();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTrack)

// Form Data
public:
	//{{AFX_DATA(CTrack)
	enum { IDD = IDD_TRACK };
	CSpinButtonCtrl	m_Spin_Year;
	CSpinButtonCtrl	m_Spin_Length;
	CSpinButtonCtrl	m_Spin_Laps;
	CComboBox	m_Team;
	CComboBox	m_Driver;
	int		m_Laps;
	int		m_Year;
	int		m_Length;
	CString	m_Record;
	//}}AFX_DATA

// Attributes
public:
	int m_Id;
// Operations
public:
	char* ConvertRaceString(double len);
	char* ConvertLapString(double len);
	void Save(CString file);
	void SetSpin();
	void FillBox();
	void Load(int id, CString file);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrack)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTrack();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTrack)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACK_H__EA937180_6C4D_11D4_8FC7_0008C7636E27__INCLUDED_)
