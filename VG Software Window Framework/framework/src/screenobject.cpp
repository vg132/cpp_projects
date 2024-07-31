#include "screenobject.hpp"

using namespace vwf;

terminal_star85::terminal CScreenObject::m_Term;

CScreenObject::CScreenObject(void)
{
}

CScreenObject::~CScreenObject(void)
{
}

CVGPtr<CScreenObject> CScreenObject::create()
{
	return(CVGPtr<CScreenObject>(new CScreenObject()));
}

bool CScreenObject::RectInRect(CVGPtr<CRect> rect)
{
	if((rect->GetTop()<m_Rect->GetTop())||(rect->GetTop()>m_Rect->GetBottom()))
		return(true);
	else if((rect->GetLeft()<m_Rect->GetLeft())||(rect->GetLeft()>m_Rect->GetRight()))
		return(true);
	else if((rect->GetRight()>m_Rect->GetRight())||(rect->GetRight()<m_Rect->GetLeft()))
		return(true);
	else if((rect->GetBottom()>m_Rect->GetBottom())||(rect->GetBottom()<m_Rect->GetTop()))
		return(true);
	return(false);
}

bool CScreenObject::PointInRect(int x, int y)
{
	if((x>=m_Rect->GetLeft())&&(x<=m_Rect->GetRight())&&(y>=m_Rect->GetTop())&&(y<=m_Rect->GetBottom()))
		return(true);
	return(false);
}

bool CScreenObject::PointInRect(CVGPtr<CPoint> point)
{
	return(PointInRect(point->GetX(),point->GetY()));
}
