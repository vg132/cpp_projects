#if !defined(AFX_FILEORGINIZER_H__D51CB1E8_9C1F_4E8D_8A94_24A8B0C3C01C__INCLUDED_)
#define AFX_FILEORGINIZER_H__D51CB1E8_9C1F_4E8D_8A94_24A8B0C3C01C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileOrginizer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileOrginizer dialog

#include "List.h"
#include "Mp3FileInfo.h"
#include "FileList.h"
#include "Progress.h"

class CFileOrginizer : public CPropertyPage
{
	DECLARE_DYNCREATE(CFileOrginizer)

private:
	CString CreateFolders();
	bool FixFile(char* FileName, char* FileTitle);
	void FileFilter(CString Filter);
	void BuildPreviewTree();
	HTREEITEM BuildNode(LPSTR szText, int Image, int SelectedImage, char* id, HTREEITEM Parant);

	List<char> m_ListLayout;
	CImageList* m_pImageList;
	HTREEITEM hChild;
	CMp3FileInfo* m_pMp3FileInfo;
	CFileList m_FileList;
	char* m_File;
	char* m_Dir;
	CProgress m_Progress;
public:
	CString GetGenreName(int id);
	void SetFile(CString file);
	void SetDirectory(CString dir);
	CFileOrginizer();
	~CFileOrginizer();

// Dialog Data
	//{{AFX_DATA(CFileOrginizer)
	enum { IDD = IDD_FILEORGINIZER };
	CButton	m_ButtonOrgenize;
	CTreeCtrl	m_Tree;
	CString	m_sTargetFolder;
	int		m_iCurDir;
	int		m_iCurFile;
	int		m_iSubDirs;
	CString	m_sFolderLayout;
	int		m_iCopy;
	int		m_iMove;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CFileOrginizer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CFileOrginizer)
	afx_msg void OnFileorginizerBrowse();
	afx_msg void OnRadioOrginizerCurfile();
	afx_msg void OnRadioOrginizerCurdir();
	afx_msg void OnRadioOrginizerSubdir();
	afx_msg void OnRadioCopy();
	afx_msg void OnRadioMove();
	afx_msg void OnChangeEditFolderlayout();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonOrginizefiles();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEORGINIZER_H__D51CB1E8_9C1F_4E8D_8A94_24A8B0C3C01C__INCLUDED_)
