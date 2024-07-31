// F1ImageInfoDlg.h : header file
//

#if !defined(AFX_F1IMAGEINFODLG_H__979DE806_1CED_4285_A469_BDAD602ED5B4__INCLUDED_)
#define AFX_F1IMAGEINFODLG_H__979DE806_1CED_4285_A469_BDAD602ED5B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CF1ImageInfoDlg dialog

class CF1ImageInfoDlg : public CDialog
{
private:
	int image_height;
	int image_widht;
	int image_depth;
	enum img_type{unknown, png, gif, bmp, jpg};
	img_type image_type;
// Construction
public:
	CF1ImageInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CF1ImageInfoDlg)
	enum { IDD = IDD_F1IMAGEINFO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CF1ImageInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CF1ImageInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int Mult(int a, int b);
	bool DecodeImage(char* filename2);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_F1IMAGEINFODLG_H__979DE806_1CED_4285_A469_BDAD602ED5B4__INCLUDED_)
