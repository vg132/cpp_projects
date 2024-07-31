#if !defined(AFX_FILECOMBOBOX_H__1B372221_41CF_4869_98A3_18F32CFC9E00__INCLUDED_)
#define AFX_FILECOMBOBOX_H__1B372221_41CF_4869_98A3_18F32CFC9E00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileComboBox window

#include "List.h"
#include "Structs.h"

#define WM_CHANGED WM_APP+0x100

class CFileComboBox : public CComboBoxEx
{
private:
	int GetIconIndex(const CString &FileName);
	void GetDrives();

	List<Drive> m_DriveList;
	CWnd *m_pParentWnd;
	CImageList m_SmallImageList;
	UINT m_Msg;
	CString m_Directory;
public:
	CFileComboBox();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetDirectory();
	void SetDirectory(CString Directory);
	void Init(CWnd *pThis, CImageList *Small, UINT message);
	~CFileComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFileComboBox)
	afx_msg void OnSelchange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILECOMBOBOX_H__1B372221_41CF_4869_98A3_18F32CFC9E00__INCLUDED_)
