#ifndef __CAUTOFILENAME__H__
#define __CAUTOFILENAME__H__

#include "List.h"
#include "Mp3FileInfo.h"
#include "FileListView.h"

class CAutoFileName : public CPropertyPage
{
	DECLARE_DYNCREATE(CAutoFileName)
private:
	CString m_File;
	CString m_Dir;
	List<char> m_ListSep;
	List<char> m_ListName;
	char *m_sTmp;
	CMp3FileInfo *m_Mp3FileInfo;
	CFileListView *m_FileListView;

	void FindFiles(CString TopFolder,int Mode=0, CString FileName="");
public:
	void SetFileListView(CFileListView* FileListView);
	CAutoFileName();
	~CAutoFileName();
	void SetFile(CString File);
	void SetDirectory(CString Dir);

// Dialog Data
	//{{AFX_DATA(CAutoFileName)
	enum { IDD = IDD_AUTOFILENAME };
	int		m_iSubDir;
	int		m_iCurFile;
	int		m_iCurDir;
	CString	m_sFileName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAutoFileName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAutoFileName)
	afx_msg void OnRadioFilenameCurfile();
	afx_msg void OnRadioFilenameCurdir();
	afx_msg void OnRadioFilenameSubdir();
	afx_msg void OnButtonCreatefilename();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
