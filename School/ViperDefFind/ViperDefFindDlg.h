// ViperDefFindDlg.h : header file
//

#if !defined(AFX_VIPERDEFFINDDLG_H__B721A562_D641_464F_8A14_53D610E600B7__INCLUDED_)
#define AFX_VIPERDEFFINDDLG_H__B721A562_D641_464F_8A14_53D610E600B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CViperDefFindDlg dialog

#include "FindFile.h"
#include "DefFix.h"

class CViperDefFindDlg : public CDialog
{
private:
	CFindFile m_FindFile;
	CDefFix m_DefFix;
	// Construction
public:
	CViperDefFindDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CViperDefFindDlg)
	enum { IDD = IDD_VIPERDEFFIND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViperDefFindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CViperDefFindDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIPERDEFFINDDLG_H__B721A562_D641_464F_8A14_53D610E600B7__INCLUDED_)
