// MemberEdit.cpp : implementation file
//

#include "stdafx.h"
#include "MedlemsSystem.h"
#include "MemberEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMemberEdit

IMPLEMENT_DYNCREATE(CMemberEdit, CFormView)

CMemberEdit::CMemberEdit()
	: CFormView(CMemberEdit::IDD)
{
	//{{AFX_DATA_INIT(CMemberEdit)
	m_Address = _T("");
	m_FirstName = _T("");
	m_LastName = _T("");
	m_MemberId = 0;
	m_MemberSence = COleDateTime::GetCurrentTime();
	m_MemberTo = COleDateTime::GetCurrentTime();
	m_Phone = _T("");
	m_DateOfBirth = COleDateTime::GetCurrentTime();
	m_MemberType = 0;
	//}}AFX_DATA_INIT
	this->m=m;
}

CMemberEdit::~CMemberEdit()
{
}

void CMemberEdit::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMemberEdit)
	DDX_Text(pDX, IDC_ADDRESS, m_Address);
	DDV_MaxChars(pDX, m_Address, 50);
	DDX_Text(pDX, IDC_FIRSTNAME, m_FirstName);
	DDV_MaxChars(pDX, m_FirstName, 50);
	DDX_Text(pDX, IDC_LASTNAME, m_LastName);
	DDV_MaxChars(pDX, m_LastName, 50);
	DDX_Text(pDX, IDC_MEMBERID, m_MemberId);
	DDV_MinMaxInt(pDX, m_MemberId, 0, 999999);
	DDX_Text(pDX, IDC_MEMBERSENCE, m_MemberSence);
	DDX_Text(pDX, IDC_MEMBERTO, m_MemberTo);
	DDX_Text(pDX, IDC_PHONE, m_Phone);
	DDV_MaxChars(pDX, m_Phone, 20);
	DDX_Text(pDX, IDC_DATEOFBIRTH, m_DateOfBirth);
	DDX_Text(pDX, IDC_MEMBERTYPE, m_MemberType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMemberEdit, CFormView)
	//{{AFX_MSG_MAP(CMemberEdit)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMemberEdit diagnostics

#ifdef _DEBUG
void CMemberEdit::AssertValid() const
{
	CFormView::AssertValid();
}

void CMemberEdit::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMemberEdit message handlers

void CMemberEdit::OnSave() 
{
	UpdateData(TRUE);	
	char *tmp;
	tmp=new char[m_FirstName.GetLength()];
	strcpy(tmp,m_FirstName);
	m->SetFirstName(tmp);
	tmp=new char[m_LastName.GetLength()];
	strcpy(tmp,m_LastName);
	m->SetLastName(tmp);
	tmp=new char[m_Address.GetLength()];
	strcpy(tmp,m_Address);
	m->SetAddress(tmp);
	tmp=new char[m_Phone.GetLength()];
	strcpy(tmp,m_Phone);
	m->SetPhone(tmp);
	m->SetMemberId(m_MemberId);
	m->SetMemberSence(&m_MemberSence);
	m->SetMemberTo(&m_MemberTo);
	m->SetBirthDay(&m_DateOfBirth);
	m->SetMemberType(m_MemberType);
}

void CMemberEdit::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
}

void CMemberEdit::LoadData()
{
	m_MemberId=m->GetMemberId();
	m_MemberSence=m->GetMemberSence();
	m_MemberTo=m->GetMemberTo();
	m_MemberType=m->GetMemberType();
	m_LastName=m->GetLastName();
	m_FirstName=m->GetFirstName();
	m_Address=m->GetAddress();
	m_Phone=m->GetPhone();
	m_DateOfBirth=m->GetBirthDay();
	
	UpdateData(FALSE);	
}
