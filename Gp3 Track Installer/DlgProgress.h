#if !defined(AFX_DLGPROGRESS_H__017BA5C6_9208_44B6_A7D1_D8E9EEBC4980__INCLUDED_)
#define AFX_DLGPROGRESS_H__017BA5C6_9208_44B6_A7D1_D8E9EEBC4980__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgProgress.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgProgress dialog

class CDlgProgress : public CDialog
{
private:
// Construction
public:
	int m_iMax;
	
	void StepIt();
	void InitProgressBar(int iMin, int iMax);
	void SetTitleText(CString title);
	void SetSubTitleText(CString title);
	void SetDataText(CString data);
	CDlgProgress(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgProgress)
	enum { IDD = IDD_DIALOG_PROGRESS };
	CProgressCtrl	m_ProgressBar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgProgress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgProgress)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROGRESS_H__017BA5C6_9208_44B6_A7D1_D8E9EEBC4980__INCLUDED_)
