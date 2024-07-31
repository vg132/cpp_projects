#include "menu.hpp"

using namespace vwf;

CMenu::CMenu():
	CActive()
{
	m_Color=CScreenObject::m_Term.White;
}

CMenu::~CMenu(void)
{
}

CVGPtr<CMenu> CMenu::create()
{
	return(CVGPtr<CMenu>(new CMenu()));
}

void CMenu::Show(CVGPtr<CRect> rect)
{
	CScreenObject::m_Term.fgcolour(m_Color);

	int left=rect->GetLeft();
	int width=(rect->GetRight()-rect->GetLeft())/m_Buttons.size();
	for(m_ButtonIter=m_Buttons.begin();m_ButtonIter!=m_Buttons.end();m_ButtonIter++)
	{
		if((*m_ButtonIter)!=m_Buttons.back())
			(*m_ButtonIter)->Show(CRect::create(rect->GetTop(),rect->GetBottom(),left,left+width));
		else
			(*m_ButtonIter)->Show(CRect::create(rect->GetTop(),rect->GetBottom(),left,rect->GetRight()));
		left+=width;
	}
}

bool CMenu::Enter()
{
	m_Color=CScreenObject::m_Term.Yellow;
	(*m_CurButton)->Enter();
	return(true);
}

void CMenu::Leave()
{
	(*m_CurButton)->Leave();
	m_Color=CScreenObject::m_Term.White;
}

void CMenu::Add(std::string label, CVGPtr<CActionBase> action)
{
	CVGPtr<CButton> tmpButton=CButton::create(label);
	tmpButton->AddAction(action);
	m_Buttons.push_back(tmpButton);
	m_CurButton=m_Buttons.begin();
}

bool CMenu::HandleEvent(Event event, CVGPtr<CScreenObject> scrObj)
{
	if(event.what==terminal::Leftarrowkey)
	{
		if((*m_CurButton)!=m_Buttons.front())
		{
			(*m_CurButton)->Leave();
			(*(--m_CurButton))->Enter();
		}
		return(true);
	}
	else if(event.what==terminal::Rightarrowkey)
	{
		if((*m_CurButton)!=m_Buttons.back())
		{
			(*m_CurButton)->Leave();
			(*(++m_CurButton))->Enter();
		}
		return(true);
	}
	return((*m_CurButton)->HandleEvent(event,scrObj));
}
