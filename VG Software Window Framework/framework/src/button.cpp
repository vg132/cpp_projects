#include "button.hpp"

using namespace vwf;
using namespace std;

CButton::CButton(string text):
	CActive()
{
	m_Text=text;
	m_Color=terminal::White;
}

CButton::~CButton(void)
{
}

CVGPtr<CButton> CButton::create(string text)
{
	return(CVGPtr<CButton>(new CButton(text)));
}

void CButton::Show(CVGPtr<CRect> rect)
{
	CScreenObject::m_Term.fgcolour(m_Color);
	CScreenObject::m_Term.box(rect->GetLeft(),rect->GetTop(),rect->GetRight(),rect->GetBottom());
	CScreenObject::m_Term.curmove(rect->GetLeft()+1,rect->GetTop()+1);
	unsigned int letters=rect->GetRight()-rect->GetLeft()-1;
	if(m_Text.length()>letters)
		cout << m_Text.substr(0,letters);
	else
		cout << m_Text;
}

bool CButton::Enter()
{
	m_Color=CScreenObject::m_Term.Yellow;
	return(true);
}

void CButton::Leave()
{
	m_Color=CScreenObject::m_Term.White;
}
