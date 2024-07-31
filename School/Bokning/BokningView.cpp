// BokningView.cpp : implementation of the CBokningView class
//

#include "stdafx.h"
#include "Bokning.h"

#include "BokningDoc.h"
#include "BokningView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBokningView

IMPLEMENT_DYNCREATE(CBokningView, CFormView)

BEGIN_MESSAGE_MAP(CBokningView, CFormView)
	//{{AFX_MSG_MAP(CBokningView)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBokningView construction/destruction

CBokningView::CBokningView()
	: CFormView(CBokningView::IDD)
{
	//{{AFX_DATA_INIT(CBokningView)
	m_PostNr = _T("");
	m_Phone = _T("");
	m_LastName = _T("");
	m_FirstName = _T("");
	m_Country = _T("");
	m_City = _T("");
	m_Address = _T("");
	m_To = 0;
	m_From = 0;
	m_Type = -1;
	m_Invoice = FALSE;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_Room = new CRoom();
	m_Room->SetName("Viktor");
	m_Room->SetPrice(500);
	m_Room->SetType(1);
	m_ListRooms.Add(m_Room);
}

CBokningView::~CBokningView()
{
}

void CBokningView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBokningView)
	DDX_Control(pDX, IDC_LIST_ROOMS, m_Rooms);
	DDX_Text(pDX, IDC_EDIT_BOOKING_POSTNR, m_PostNr);
	DDX_Text(pDX, IDC_EDIT_BOOKING_PHONE, m_Phone);
	DDX_Text(pDX, IDC_EDIT_BOOKING_LASTNAME, m_LastName);
	DDX_Text(pDX, IDC_EDIT_BOOKING_FIRSTNAME, m_FirstName);
	DDX_Text(pDX, IDC_EDIT_BOOKING_COUNTRY, m_Country);
	DDX_Text(pDX, IDC_EDIT_BOOKING_CITY, m_City);
	DDX_Text(pDX, IDC_EDIT_BOOKING_ADDRESS, m_Address);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_TO, m_To);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_FROM, m_From);
	DDX_CBIndex(pDX, IDC_COMBO_TYPE, m_Type);
	DDX_Check(pDX, IDC_CHECK_INVOICE, m_Invoice);
	//}}AFX_DATA_MAP
}

BOOL CBokningView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CBokningView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	EnableBooking(false);
}

/////////////////////////////////////////////////////////////////////////////
// CBokningView printing

BOOL CBokningView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBokningView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBokningView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CBokningView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CBokningView diagnostics

#ifdef _DEBUG
void CBokningView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBokningView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CBokningDoc* CBokningView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBokningDoc)));
	return (CBokningDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBokningView message handlers

void CBokningView::EnableBooking(bool enable)
{
	GetDlgItem(IDC_EDIT_BOOKING_FIRSTNAME)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_BOOKING_ADDRESS)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_BOOKING_CITY)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_BOOKING_COUNTRY)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_BOOKING_LASTNAME)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_BOOKING_POSTNR)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_BOOKING_PHONE)->EnableWindow(enable);
	GetDlgItem(IDC_CHECK_INVOICE)->EnableWindow(enable);
	GetDlgItem(IDC_BUTTON_BOOK)->EnableWindow(enable);
	GetDlgItem(IDC_BUTTON_CANCEL)->EnableWindow(enable);

	GetDlgItem(IDC_STATIC_FIRSTNAME)->EnableWindow(enable);
	GetDlgItem(IDC_STATIC_ADDRESS)->EnableWindow(enable);
	GetDlgItem(IDC_STATIC_POSTNR)->EnableWindow(enable);
	GetDlgItem(IDC_STATIC_COUNTRY)->EnableWindow(enable);
	GetDlgItem(IDC_STATIC_PHONE)->EnableWindow(enable);
	GetDlgItem(IDC_STATIC_CITY)->EnableWindow(enable);
	GetDlgItem(IDC_STATIC_LASTNAME)->EnableWindow(enable);
	GetDlgItem(IDC_STATIC_BOOKFRAME)->EnableWindow(enable);
}

void CBokningView::OnButtonSearch() 
{/*
	UpdateData(TRUE);
	for(int i=0;i<m_ListRooms.GetSize();i++)
	{
		m_Room=m_ListRooms.GetItem(i);
		if(m_Room->IsRoomFree(m_From,m_To))
		{
//			MessageBox("Room is Free!");
			m_Person=new CPerson();
			m_Person->SetFirstName("Kalle");
			m_Person->SetLastName("Anka");
			m_Room->AddBokning(m_Person,m_From,m_To);
		}	
		else
			MessageBox("Room is not free!");
	}*/
	ofstream ofs;
	ofs.open("c:\\test.txt");
	m_Room = m_ListRooms.GetItem(0);
	ofs << *m_Room;
	ofs.close();
}
