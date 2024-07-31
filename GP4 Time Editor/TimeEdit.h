#pragma	once
#include "afxwin.h"


// CTimeEdit dialog

class	CTimeEdit	:	public CDialog
{
	DECLARE_DYNAMIC(CTimeEdit)

public:
	CTimeEdit(CWnd*	pParent	=	NULL);	 //	standard constructor
	virtual	~CTimeEdit();

// Dialog	Data
	enum { IDD = IDD_TIME_EDIT };

protected:
	virtual	void DoDataExchange(CDataExchange* pDX);		// DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	int	i;
	afx_msg	void OnBnClickedButtonCancel();
	CEdit	m_Name;
	CEdit	m_Team;
	CEdit	m_Date;
	CEdit	m_Time;
};
