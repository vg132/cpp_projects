#include "edit.hpp"

using namespace vwf;
using namespace std;

CEdit::CEdit(void):
	CActive()
{
	m_Text="";
	m_CurPos=0;
}

CEdit::CEdit(string str):
	CActive()
{
	m_Text=str;
	m_CurPos=0;
	m_Color=CScreenObject::m_Term.White;
}

CEdit::~CEdit(void)
{
}

CVGPtr<CEdit> CEdit::create()
{
	return(CVGPtr<CEdit>(new CEdit()));
}

CVGPtr<CEdit> CEdit::create(string str)
{
	return(CVGPtr<CEdit>(new CEdit(str)));
}

void CEdit::Show(CVGPtr<CRect> rect)
{
	CScreenObject::m_Term.fgcolour(m_Color);
	CScreenObject::m_Term.box(rect->GetLeft(),rect->GetTop(),rect->GetRight(),rect->GetBottom());
	CScreenObject::m_Term.curmove(rect->GetLeft()+1,rect->GetTop()+1);
	if(m_Text.length()>0)
	{
		unsigned int letters=rect->GetRight()-rect->GetLeft()-1;
		unsigned int tmpPos=m_CurPos;
		if(tmpPos>=m_Text.length())
			tmpPos=m_Text.length()-1;
		if(tmpPos>=letters-1)
		{
			tmpPos-=(letters-1);
			if(tmpPos<0)
				tmpPos=0;
		}
		else
		{
			tmpPos=0;
		}
		cout << m_Text.substr(tmpPos,letters);
	}
}

bool CEdit::Enter()
{
	m_Color=CScreenObject::m_Term.Yellow;
	return(true);
}

void CEdit::Leave()
{
	m_Color=CScreenObject::m_Term.White;
}

bool CEdit::HandleEvent(Event event, CVGPtr<CScreenObject> scrObj)
{
	if((event.what>=32)&&(event.what<=126))
	{
		m_Text+=(char)event.what;
		m_CurPos=m_Text.length()-1;
		return(true);
	}
	else if(event.what==terminal::DELkey)
	{
		if(m_Text.length()>0)
			m_Text=m_Text.substr(0,m_Text.length()-1);
		m_CurPos=m_Text.length()-1;
		return(true);
	}
	else if(event.what==terminal::Leftarrowkey)
	{
		if(m_CurPos>0)
			m_CurPos--;
		return(true);
	}
	else if(event.what==terminal::Rightarrowkey)
	{
		if(m_CurPos<m_Text.length())
			m_CurPos++;
		return(true);
	}
	CActive::HandleEvent(event,scrObj);
	return(false);
}
