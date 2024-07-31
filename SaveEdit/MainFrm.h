// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__4CE8A828_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_MAINFRM_H__4CE8A828_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Common.h"

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:
	CFile f;
	int iRead;
	CString m_DataFile;
	int iCur;
	CString m_RealName;
	CString m_GPWPath;
	CCommon m_Common;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ShowSponsors(int id);
	void ShowWorkDesign(int id);
	void ShowMain();
	void SelectGPWPath();
	void SetEnable(bool open);
	void SaveCur();
	void ShowWorkMech(int id);
	void ShowLicensing(int id);
	void ShowDepMechanics(int id);
	void ShowDepEngineering(int id);
	void ShowDepDesign(int id);
	void ShowDepCommercial(int id);
	void ShowMechanics(int id);
	void ShowEngineering(int id);
	void ShowDesign(int id);
	void ShowCommercial(int id);
	void ShowTrack(int id);
	void ShowInfo();
	void ShowFinanceTeam(int id);
	void ShowTechTeam(int id);
	void ShowDriver(int id);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CSplitterWnd m_wndSplitter;
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTempView1();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSavefile();
	afx_msg void OnFileSavefileas();
	afx_msg void OnFileClosefile();
	afx_msg void OnEditGpwdirectory();
	afx_msg void OnEditRungpw();
	afx_msg void OnEditSavefiledirectory();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__4CE8A828_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
