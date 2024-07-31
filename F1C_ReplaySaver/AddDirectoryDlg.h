#pragma once
#include "afxwin.h"


// CAddDirectoryDlg dialog

class CAddDirectoryDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddDirectoryDlg)

public:
	CAddDirectoryDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAddDirectoryDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADDREPLAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Executable;
	CString m_ReplayDirectory;
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButtonCancel();
	CString m_Name;
	afx_msg void OnBnClickedButtonBrowseExecutable();
	afx_msg void OnBnClickedButtonBrowseDirectory();
};
