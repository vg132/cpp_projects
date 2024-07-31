#ifndef __CAUTOTAGEDIT__H__
#define __CAUTOTAGEDIT__H__

/////////////////////////////////////////////////////////////////////////////
// CAutoTagEdit dialog

#include "Mp3FileInfo.h"
#include "List.h"

class CAutoTagEdit : public CPropertyPage
{
	DECLARE_DYNCREATE(CAutoTagEdit)

private:
	void FindFiles(CString TopFolder,int Mode=0,CString FileName="");
	void EnableTagFromName(bool enable);
	void EnableNameFromTag(bool enable);
	void FileFilter(CString Filter);
	void FindSep(CString List);
	void SetTag(int Pos, CString Text);

	CString m_File;
	CString m_Dir;
	CMp3FileInfo *m_FileInfo;
	List<char> m_ListSep;
	List<char> m_ListName;

public:
	void SplitFileName(CString Name);
	void SetFile(CString File);
	void SetDirectory(CString Dir);
	CAutoTagEdit();
	~CAutoTagEdit();

// Dialog Data
	//{{AFX_DATA(CAutoTagEdit)
	enum { IDD = IDD_AUTOTAGEDIT };
	int		m_TagFromName;
	int		m_NameFromTag;
	CString	m_TagFileFilter;
	int		m_CurDir;
	int		m_CurFile;
	int		m_SubFolders;
	CString	m_Year;
	CString	m_Artist;
	CString	m_Album;
	BOOL	m_bYear;
	BOOL	m_bArtist;
	BOOL	m_bAlbum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAutoTagEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAutoTagEdit)
	afx_msg void OnRadioCurfile();
	afx_msg void OnRadioCurdir();
	afx_msg void OnRadioSubdir();
	afx_msg void OnButtonCreatetag();
	afx_msg void OnTagCheckArtist();
	afx_msg void OnTagCheckAlbum();
	afx_msg void OnTagCheckYear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
