#ifndef __CTAGEDIT__H__
#define __CTAGEDIT__H__

#include "Mp3FileInfo.h"

class CTagEdit : public CPropertyPage
{
	DECLARE_DYNCREATE(CTagEdit)

private:
	CMp3FileInfo *m_FileInfo;
	void EnableTagEdit(bool enable);
	bool m_CurrentState;
public:
	void ResetControls();
	void SetAutoSave(int autosave);
	int GetAutoSave();
	void DisableAndSave();
	void SetFile(CString FileName, bool Silent);
	void SaveTag();
	CTagEdit();
	~CTagEdit();

// Dialog Data
	//{{AFX_DATA(CTagEdit)
	enum { IDD = IDD_TAGEDIT };
	CComboBox	m_Genre;
	CString	m_Album;
	CString	m_Artist;
	BOOL	m_AutoSave;
	CString	m_Bitrate;
	CString	m_Comments;
	CString	m_Copyright;
	CString	m_CRC;
	CString	m_Emphasis;
	CString	m_FileSize;
	CString	m_Frequency;
	CString	m_MpegVersion;
	CString	m_Original;
	CString	m_Title;
	CString	m_Year;
	CString	m_Length;
	int		m_Track;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTagEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTagEdit)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
