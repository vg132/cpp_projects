// BannerTestDlg.h : header file
//

#if !defined(AFX_BANNERTESTDLG_H__11230FC7_AE5A_4A32_9A70_F9E7FF9D0FBB__INCLUDED_)
#define AFX_BANNERTESTDLG_H__11230FC7_AE5A_4A32_9A70_F9E7FF9D0FBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBannerTestDlg dialog

#include "MultiColorStatic.h"
#include "BannerStatic.h"

class CBannerTestDlg : public CDialog
{
// Construction
public:
	CBannerTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBannerTestDlg)
	enum { IDD = IDD_BANNERTEST_DIALOG };
	CBannerStatic	m_Banner;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBannerTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBannerTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BANNERTESTDLG_H__11230FC7_AE5A_4A32_9A70_F9E7FF9D0FBB__INCLUDED_)
