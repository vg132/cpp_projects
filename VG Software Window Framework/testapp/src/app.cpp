#include "app.hpp"

using namespace std;
using namespace vwf;

CApp::CApp(void)
{
}

CApp::~CApp(void)
{
}

void CApp::Start()
{
	CVGPtr<CRect> m_Rect=CRect::create(1,30,1,30);
	CVGPtr<CFrame> m_Frame=CFrame::create(m_Rect);

	CVGPtr<CLabel> m_Label=CLabel::create("Label 1");
	CVGPtr<CEdit> m_Edit=CEdit::create("Viktor");
	
	m_Button=CButton::create("Button");
	event.what=terminal::ENTER;
	m_Action=CAction<CApp>::create(this,&CApp::Action,event);
	m_Button->AddAction(dynamic_ptr_cast<CActionBase>(m_Action));

	CVGPtr<CMenu> m_Menu=CMenu::create();
	m_Menu->Add("viktor Menu",m_Action);
	m_Menu->Add("Anka Menu",m_Action);
	try
	{
		m_Frame->AddScreenObject(dynamic_ptr_cast<CScreenObject>(m_Label),CPoint::create(2,2),CSize::create(7,1));
		m_Frame->AddScreenObject(dynamic_ptr_cast<CScreenObject>(m_Button),CPoint::create(2,5),CSize::create(8,3));
		m_Frame->AddScreenObject(dynamic_ptr_cast<CScreenObject>(m_Edit),CPoint::create(2,10),CSize::create(15,3));
		m_Frame->AddScreenObject(dynamic_ptr_cast<CScreenObject>(m_Menu),CPoint::create(1,28),CSize::create(30,3));
		m_Frame->Show();
	}
	catch(out_of_range& oor)
	{
		cout << "error out of range" << endl;
	}
}

void CApp::Action(Event event, CVGPtr<CScreenObject> scrObj)
{
	static int kalle=0;
	if(kalle==0)
		m_Button->SetText("Viktor");
	else if(kalle==1)
		m_Button->SetText("Anka");
	else if(kalle==2)
		m_Button->SetText("Tanka");
	else if(kalle==3)
		m_Button->SetText("Klanka");
	else if(kalle==4)
	{
		m_Button->SetText("Plan");
		kalle=-1;
	}
	kalle++;
}

void CApp::EditAction(Event event, CVGPtr<CScreenObject> scrObj)
{
	m_Button->SetText("Edit!!!");
}
