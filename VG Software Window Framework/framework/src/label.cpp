#include "label.hpp"

using namespace vwf;
using namespace std;

CLabel::CLabel(string text):
	CPassive()
{
	m_Text=text;
}

CLabel::~CLabel(void)
{
}

CVGPtr<CLabel> CLabel::create(string text)
{
	return(CVGPtr<CLabel>(new CLabel(text)));
}

void CLabel::Show(CVGPtr<CRect> rect)
{
	CScreenObject::m_Term.curmove(rect->GetLeft(),rect->GetTop());
	unsigned int letters=rect->GetRight()-rect->GetLeft()+1;
	if(m_Text.length()>letters)
		cout << m_Text.substr(0,letters);
	else
		cout << m_Text;
}
