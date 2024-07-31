#if !defined(AFX_FILELISTVIEW_H__A8914D76_BC75_4037_8694_D245118BCF9E__INCLUDED_)
#define AFX_FILELISTVIEW_H__A8914D76_BC75_4037_8694_D245118BCF9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileListView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileListView window

#include "List.h"
#include "Structs.h"
#include "Mp3FileInfo.h"

#define WM_FILESELECTED WM_APP+0x200
#define WM_FOLDERSELECTED WM_APP+0x300
#define WM_CHANGEDFOLDER WM_APP+0x400
#define WM_NONSELECTED WM_APP+0x500
#define WM_SAVEFILE WM_APP+0x700

class CFileListView : public CListCtrl
{
private:
	void GetDrivers();
	void MyComputer();
	static int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
	void SplitPatterns(char *FilePattern);
	int GetIconIndex(const CString &FileName);

	List<char> m_PatternList;
	CString m_CurrentFile;
	CString m_CurrentPath;
	CString m_Player;
	CString m_File;
	CMp3FileInfo *m_pMp3FileInfo;
	bool m_Copy;
	bool m_Move;
	/**
	 * 0 = Not selected
	 * 1 = Folder selected
	 * 2 = File selected
	 */
	int m_SelectedFileType;
	CWnd *m_pParentWnd;
	UINT m_Msg;

public:
	List<Drive> m_DriveList;
	CFileListView();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileListView)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetFileTitle(CString path);
	void SetPlayer(CString player);
	void Up1Level();
	CString GetFile();
	CString GetDirectory();
	void SetDirectory(CString Path);
	bool InitFileList(CWnd *pParentWnd, char *FilePattern, CImageList *Small, CImageList *Large, UINT msg);
	virtual ~CFileListView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFileListView)
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditDelete();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnEditPlay();
	afx_msg void OnEditClearid3tag();
	afx_msg void OnEditRemoveid3tag();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILELISTVIEW_H__A8914D76_BC75_4037_8694_D245118BCF9E__INCLUDED_)