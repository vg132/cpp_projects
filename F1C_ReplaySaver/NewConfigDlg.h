#pragma once


// CNewConfigDlg dialog

class CNewConfigDlg : public CDialog
{
	DECLARE_DYNAMIC(CNewConfigDlg)

public:
	CNewConfigDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewConfigDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_NEW_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButtonCancel();
	CString m_Name;
	CString m_ReplayDirectory;
	CString m_Executable;
	CString m_StartupDirectory;
	afx_msg void OnBnClickedButtonBrowseDirectory();
	afx_msg void OnBnClickedButtonBrowseExecutable();
};
