#ifndef __1FE24CAD5DFEACEC24DFE__F1C_REPLAYSAVERDLG__H__
#define __1FE24CAD5DFEACEC24DFE__F1C_REPLAYSAVERDLG__H__

// F1C_ReplaySaverDlg.h : header file
//

#include "DirectoryChanges.h"
#include "ReplayDirWatcher.h"
#include "afxwin.h"
#include "ReplayInfo.h"
#include "NewConfigDlg.h"

// CF1C_ReplaySaverDlg dialog
class CF1C_ReplaySaverDlg : public CDialog
{
private:
	CString m_strStartupPath;
	CMapStringToPtr m_mapReplayInfo;
	CDirectoryChangeWatcher m_DirWatcher;
	CReplayDirWatcher m_ReplayWatcher;
	CListBox m_lstDirectorys;
	int m_iDefaut;

	bool LoadConfig(void);
	bool SaveConfig(void);

public:
	CF1C_ReplaySaverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_F1C_REPLAYSAVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdddir();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonDeldir();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonDefault();
	afx_msg void OnClose();
};

#endif // __1FE24CAD5DFEACEC24DFE__F1C_REPLAYSAVERDLG__H__
