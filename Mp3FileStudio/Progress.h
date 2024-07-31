#if !defined(AFX_PROGRESS_H__8AD0491C_D970_4118_AEC9_F01CF303365D__INCLUDED_)
#define AFX_PROGRESS_H__8AD0491C_D970_4118_AEC9_F01CF303365D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Progress.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgress dialog

class CProgress : public CDialog
{
// Construction
public:
	void StepProgressBar();
	void SetProgressBar(int Max);
	void SetHeader(char* Header);
	void SetHeader(CString Header);
	void SetText(CString Text);
	void SetText(char* Text);
	CProgress(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProgress)
	enum { IDD = IDD_PROGRESS };
	CProgressCtrl	m_ProgressBar;
	CString	m_sText;
	CString	m_sHeader;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProgress)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESS_H__8AD0491C_D970_4118_AEC9_F01CF303365D__INCLUDED_)
