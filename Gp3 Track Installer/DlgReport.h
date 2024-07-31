#if !defined(AFX_DLGREPORT_H__AE1EC27F_E746_4EFA_907D_BD908077228E__INCLUDED_)
#define AFX_DLGREPORT_H__AE1EC27F_E746_4EFA_907D_BD908077228E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgReport.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgReport dialog

#include "Language.h"

class CDlgReport : public CDialog
{
private:
	CLanguage* m_pLang;
	bool m_Gp3Form;
	char* m_pText;
public:
	void Init(CLanguage* lang, char* text=NULL, bool gp3form=true);
	CDlgReport(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgReport)
	enum { IDD = IDD_DIALOG_REPORT };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgReport)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgReport)
	afx_msg void OnButtonOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGREPORT_H__AE1EC27F_E746_4EFA_907D_BD908077228E__INCLUDED_)
