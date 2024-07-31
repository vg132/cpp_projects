// Gp1 Lap EditorDlg.h : header file
//

#if !defined(AFX_GP1LAPEDITORDLG_H__E5BC7006_3681_11D4_A39C_0008C7636E27__INCLUDED_)
#define AFX_GP1LAPEDITORDLG_H__E5BC7006_3681_11D4_A39C_0008C7636E27__INCLUDED_

#include "Common.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGp1LapEditorDlg dialog

class CGp1LapEditorDlg : public CDialog
{
// Construction
public:
	CGp1LapEditorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGp1LapEditorDlg)
	enum { IDD = IDD_GP1LAPEDITOR_DIALOG };
	CListCtrl	m_Files;
	BYTE	m_Laps;
	int		m_FileExt;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGp1LapEditorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGp1LapEditorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnEditSettrackpath();
	afx_msg void OnHelpOnline();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveas();
	afx_msg void OnSave();
	afx_msg void OnFileSave();
	afx_msg void OnItemchangedFiles(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeFileext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void CheckSum();
	void ListFiles();
	void Save();
	void Load();
	CCommon m_Common;
	CString szPath;
	CString m_CurrentFile;
	byte bLaps;
	CImageList * m_pImageList;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GP1LAPEDITORDLG_H__E5BC7006_3681_11D4_A39C_0008C7636E27__INCLUDED_)
