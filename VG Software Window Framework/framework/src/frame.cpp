#include "frame.hpp"
#include <iostream>

using namespace vwf;
using namespace terminal_star85;

CFrame::CFrame(CVGPtr<CRect> rect):
	CActive()
{
	m_Rect=rect;
}

CFrame::CFrame():
	CActive()
{
	m_Rect=CRect::create(0,CScreenObject::m_Term.height(),0,CScreenObject::m_Term.width());
}

CFrame::~CFrame(void)
{
}

void CFrame::Show()
{
	m_CurrentObjectIter=m_ObjectData.end();
	SetFocus();
	DrawScreen();
	for(Event event=m_Term.getNextEvent();event.what!=/*terminal::Endkey*/400;event=m_Term.getNextEvent())
	{
		if(event.what==terminal::TAB)
		{	
			SetFocus();
		}
		else if(m_CurrentObjectIter!=m_ObjectData.end())
		{
			(*m_CurrentObjectIter)->GetObject()->HandleEvent(event,(*m_CurrentObjectIter)->GetObject());
		}
		DrawScreen();
	}
}

void CFrame::SetFocus()
{	
	if(m_CurrentObjectIter!=m_ObjectData.end())
	{
		(*m_CurrentObjectIter)->GetObject()->Leave();
		m_CurrentObjectIter=find_if(++m_CurrentObjectIter,m_ObjectData.end(),CFocusHelp());
	}
	if(m_CurrentObjectIter==m_ObjectData.end())
		m_CurrentObjectIter=find_if(m_ObjectData.begin(),m_ObjectData.end(),CFocusHelp());
}

void CFrame::DrawScreen()
{
	m_Term.savecur();
	CScreenObject::m_Term.clrscr();
	CScreenObject::m_Term.box(m_Rect->GetTop(),m_Rect->GetLeft(),m_Rect->GetBottom(),m_Rect->GetRight());

	for(m_ObjectIter=m_ObjectData.begin();m_ObjectIter!=m_ObjectData.end();m_ObjectIter++)
	{
		(*m_ObjectIter)->GetObject()->Show((*m_ObjectIter)->GetRect());
	}
	m_Term.restcur();
}

void CFrame::Hide()
{

}

CVGPtr<CFrame> CFrame::create(CVGPtr<CRect> rect)
{
	return(CVGPtr<CFrame>(new CFrame(rect)));
}

CVGPtr<CFrame> CFrame::create()
{
	return(CVGPtr<CFrame>(new CFrame()));
}

void CFrame::AddScreenObject(CVGPtr<CScreenObject> object,CVGPtr<CPoint> pos, CVGPtr<CSize> size)
{
	AddScreenObject(object,CRect::create(pos->GetY(),pos->GetY()+size->GetHeight()-1,pos->GetX(),pos->GetX()+size->GetWidth()-1));
}

void CFrame::AddScreenObject(CVGPtr<CScreenObject> object, CVGPtr<CRect> rect)
{
	if(RectInRect(rect))
		throw(std::out_of_range("All components added to this component must be within its limits."));
	m_ObjectData.push_back(CObjectData::create(object,rect));
}

void CFrame::RemoveScreenObject(CVGPtr<CScreenObject> object)
{
	for(m_ObjectIter=m_ObjectData.begin();m_ObjectIter!=m_ObjectData.end();m_ObjectIter++)
	{
		if((*m_ObjectIter)->GetObject()==object)
		{
			m_ObjectData.erase(m_ObjectIter);
			break;
		}
	}
	DrawScreen();
}
