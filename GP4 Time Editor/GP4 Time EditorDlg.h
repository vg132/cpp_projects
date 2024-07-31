// GP4 Time EditorDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "TimeEdit.h"

struct RecInfo
{
	char pp_name[24];
	char pp_team[16];
	int pp_time;
	short pp_date;
	char fl_name[24];
	char fl_team[14];
	int fl_time;
	short fl_date;
	char empty1[2];
	char winner_name[24];
	char winner_team[14];
	char rec_fl_name[24];
	char rec_fl_team[14];
	int rec_fl_time;
	char rec_fl_year[4];
	char empty2[4];
	char rec_pp_name[24];
	char rec_pp_team[16];
	int rec_pp_time;
	char rec_pp_year[4];
	char empty3[4];
};


// CGP4TimeEditorDlg dialog
class CGP4TimeEditorDlg : public CDialog
{
// Construction
public:
	CGP4TimeEditorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GP4TIMEEDITOR_DIALOG };

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
private:
	// Read the file and show all records in the list view
	bool ReadSaveFile(char* Filename);
	bool CheckSum(char* FileName, bool gp4=true);

	RecInfo m_Records[17];
	CListCtrl m_List;
	CTabCtrl m_Tab;
public:
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	void ShowRecords(void);
	char* GetTime(int time, char* buffer);
	char* GetDate(int date, char* buffer);
	afx_msg void OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
};
