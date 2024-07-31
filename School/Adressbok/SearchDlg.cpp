// SearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Adressbok.h"

#include "AdressbokDlg.h"
#include "SearchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg dialog


CSearchDlg::CSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchDlg)
	m_bFirstName = FALSE;
	m_bAddress = FALSE;
	m_bCity = FALSE;
	m_bLastName = FALSE;
	m_bPhone = FALSE;
	m_bPostNr = FALSE;
	m_Address = _T("");
	m_City = _T("");
	m_FirstName = _T("");
	m_LastName = _T("");
	m_Phone = _T("");
	m_PostNr = _T("");
	//}}AFX_DATA_INIT
}

void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchDlg)
	DDX_Check(pDX, IDC_CHECK_FIRSTNAME, m_bFirstName);
	DDX_Check(pDX, IDC_CHECK_ADDRESS, m_bAddress);
	DDX_Check(pDX, IDC_CHECK_CITY, m_bCity);
	DDX_Check(pDX, IDC_CHECK_LASTNAME, m_bLastName);
	DDX_Check(pDX, IDC_CHECK_PHONE, m_bPhone);
	DDX_Check(pDX, IDC_CHECK_POSTNR, m_bPostNr);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_Address);
	DDV_MaxChars(pDX, m_Address, 100);
	DDX_Text(pDX, IDC_EDIT_CITY, m_City);
	DDV_MaxChars(pDX, m_City, 100);
	DDX_Text(pDX, IDC_EDIT_FIRSTNAME, m_FirstName);
	DDV_MaxChars(pDX, m_FirstName, 100);
	DDX_Text(pDX, IDC_EDIT_LASTNAME, m_LastName);
	DDV_MaxChars(pDX, m_LastName, 100);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_Phone);
	DDV_MaxChars(pDX, m_Phone, 100);
	DDX_Text(pDX, IDC_EDIT_POSTNR, m_PostNr);
	DDV_MaxChars(pDX, m_PostNr, 6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchDlg)
	ON_BN_CLICKED(IDC_CHECK_FIRSTNAME, OnCheckFirstname)
	ON_BN_CLICKED(IDC_CHECK_LASTNAME, OnCheckLastname)
	ON_BN_CLICKED(IDC_CHECK_ADDRESS, OnCheckAddress)
	ON_BN_CLICKED(IDC_CHECK_POSTNR, OnCheckPostnr)
	ON_BN_CLICKED(IDC_CHECK_CITY, OnCheckCity)
	ON_BN_CLICKED(IDC_CHECK_PHONE, OnCheckPhone)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg message handlers

void CSearchDlg::OnCheckFirstname() 
{
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT_FIRSTNAME)->EnableWindow(m_bFirstName);
}

void CSearchDlg::OnCheckLastname() 
{
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT_LASTNAME)->EnableWindow(m_bLastName);
}

void CSearchDlg::OnCheckAddress() 
{
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT_ADDRESS)->EnableWindow(m_bAddress);

}

void CSearchDlg::OnCheckPostnr() 
{
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT_POSTNR)->EnableWindow(m_bPostNr);
}

void CSearchDlg::OnCheckCity() 
{
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT_CITY)->EnableWindow(m_bCity);
}

void CSearchDlg::OnCheckPhone() 
{
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT_PHONE)->EnableWindow(m_bPhone);
}

void CSearchDlg::OnButtonCancel() 
{
	OnCancel();	
}

void CSearchDlg::OnButtonSearch() 
{
	OnOK();
}
