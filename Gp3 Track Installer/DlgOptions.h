#if !defined(AFX_DLGOPTIONS_H__AA08BE2C_4DB6_4DB3_B1DE_1F44CB375211__INCLUDED_)
#define AFX_DLGOPTIONS_H__AA08BE2C_4DB6_4DB3_B1DE_1F44CB375211__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOptions.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgOptions dialog

#include "Language.h"
#include "RegEdit.h"

class CDlgOptions : public CDialog
{
private:
	CLanguage* m_pLang;
	CRegEdit m_RegEdit;
	char* m_pLanguage;
// Construction
public:
	void FindLanguageFiles();
	char* BrowseForFolders(char* title);
	void Init(CLanguage* lang);
	CDlgOptions(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgOptions)
	enum { IDD = IDD_DIALOG_OPTIONS };
	CComboBox	m_Language;
	BOOL	m_bOverwrite;
	BOOL	m_bRemove;
	BOOL	m_bShowGp3Form;
	BOOL	m_bShowReport;
	BOOL	m_bTempFolder;
	CString	m_szFolder;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgOptions)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckTempFolder();
	afx_msg void OnButtonUnzipBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOPTIONS_H__AA08BE2C_4DB6_4DB3_B1DE_1F44CB375211__INCLUDED_)
