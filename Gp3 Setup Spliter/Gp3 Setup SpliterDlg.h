// Gp3 Setup SpliterDlg.h : header file
//

#if !defined(AFX_GP3SETUPSPLITERDLG_H__D16E2472_0133_4B8C_BEB3_1DFE8042CB44__INCLUDED_)
#define AFX_GP3SETUPSPLITERDLG_H__D16E2472_0133_4B8C_BEB3_1DFE8042CB44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGp3SetupSpliterDlg dialog

#include "Misc.h"
#include "Front.h"
#include "Rear.h"
#include "SetupFile.h"
#include "List.h"

class CGp3SetupSpliterDlg : public CDialog
{
private:
	void SelChange();
	HTREEITEM BuildNode(LPSTR szText, int Image, int SelectedImage, char* id, HTREEITEM Parant);
	void BuildTree();
	void LoadSetup();
	char* GetFileTitle(char* FileName);

	CSetupFile *m_SetupFile;
	CMisc m_Misc;
	CFront m_Front;
	CRear m_Rear;
	CPropertySheet m_PropertySheet;
	CImageList *m_pImageList;
	CDataList<CSetupFile> m_SetupFileList;
	int m_iCurNode;	//Cur nr in list
	int m_iCurType; //Cur setup type
	int m_iCurTrack;	//Cur track
	int m_Id;
	char m_Gp3TrackName[16][18];
	char m_Gp2TrackName[16][18];
public:
	void SaveSetup();
	CGp3SetupSpliterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGp3SetupSpliterDlg)
	enum { IDD = IDD_GP3SETUPSPLITER_DIALOG };
	CTreeCtrl	m_Tree;
	int		m_RightFrontRearRebound;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGp3SetupSpliterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGp3SetupSpliterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileExit();
	afx_msg void OnHelpVgsoftwareonline();
	afx_msg void OnHelpAbout();
	afx_msg void OnFileOpen();
	afx_msg void OnFileClose();
	afx_msg void OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFileSaveasgp2();
	afx_msg void OnFileSaveasgp3();
	afx_msg void OnFileSave();
	afx_msg void OnFileExtractasgp2();
	afx_msg void OnFileExtractasgp3();
	afx_msg void OnRclickTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFileCloseall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GP3SETUPSPLITERDLG_H__D16E2472_0133_4B8C_BEB3_1DFE8042CB44__INCLUDED_)