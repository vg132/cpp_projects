// Grand Prix WorldDlg.h : header file
//

#if !defined(AFX_GRANDPRIXWORLDDLG_H__BBB24A12_AA07_4335_A3FB_2564745D32F6__INCLUDED_)
#define AFX_GRANDPRIXWORLDDLG_H__BBB24A12_AA07_4335_A3FB_2564745D32F6__INCLUDED_

#include "Data.h"
#include "Common.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGrandPrixWorldDlg dialog

class CGrandPrixWorldDlg : public CDialog
{
// Construction
public:
	CGrandPrixWorldDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	//{{AFX_DATA(CGrandPrixWorldDlg)
	enum { IDD = IDD_GRANDPRIXWORLD_DIALOG };
	CSliderCtrl	m_Morale;
	CTreeCtrl	m_Tree;
	CString	m_Root_Team;
	int		m_Root_Year;
	int		m_Root_Years;
	int		m_Root_Points;
	CString	m_Root_NextRace;
	int		m_Root_Pos;
	CString	m_Root_Player;
	CString	m_Root_Created;
	CString	m_Root_Modified;
	int		m_Root_Score;
	int		m_Other_Ability;
	int		m_Other_WCBonus;
	int		m_Other_Salary;
	int		m_Other_RaceBonus;
	int		m_Other_LastYear;
	int		m_Commercial_Ability;
	int		m_Commercial_LastYear;
	int		m_Commercial_Royalty;
	int		m_Commercial_Salary;
	int		m_Driver_CHBonus;
	int		m_Driver_Concentration;
	int		m_Driver_Experience;
	int		m_Driver_Morale;
	int		m_Driver_Overtaking;
	int		m_Driver_Points;
	int		m_Driver_RaceBonus;
	int		m_Driver_Salary;
	int		m_Driver_Skill;
	int		m_Driver_Speed;
	int		m_Driver_Stamina;
	int		m_Driver_WetWether;
	int		m_Team_Budget;
	int		m_Team_Points;
	int		m_Team_TestPrice;
	int		m_OtherRoot_Average;
	int		m_OtherRoot_Excellent;
	int		m_OtherRoot_Good;
	int		m_OtherRoot_Morale;
	int		m_OtherRoot_Trainee;
	int		m_OtherRoot_VeryGood;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrandPrixWorldDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int iLastPos;
	int iCurPos;
	/*0=Team
	  1=Driver
	  2=Other
	  3=Other Root
	  4=Root
	  5=Commercial
	*/
	int iCurShow;
	int iShowNext;
	// Generated message map functions
	//{{AFX_MSG(CGrandPrixWorldDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileExit();
	afx_msg void OnFileOpen();
	afx_msg void OnClickTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangedTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangingTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveas();
	afx_msg void OnHelpAbout();
	afx_msg void OnHelpOnline();
	afx_msg void OnEDITGPWPath();
	afx_msg void OnEditBackup();
	afx_msg void OnFileExport();
	afx_msg void OnFileImport();
	afx_msg void OnFileSaveShort();
	afx_msg void OnFileClose();
	afx_msg void OnHelpHowto();
	afx_msg void OnHelpMenuhelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SaveLastClick();
	void ShowOtherRoot(bool show);
	void ShowOther(bool show);
	void ShowTeam(bool show);
	void ShowCommercial(bool show);
	void ShowRoot(bool show);
	void ShowDriver(bool show);

	void SaveArray();
	void GetFileInfo();
	CString GetFile(CString sPath);

	Data m_Data;
	CCommon m_Common;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRANDPRIXWORLDDLG_H__BBB24A12_AA07_4335_A3FB_2564745D32F6__INCLUDED_)
