#include "rect.hpp"

using namespace vwf;

CRect::CRect()
{
}

CRect::CRect(int top, int bottom, int left, int right)
{
	m_iTop=top;
	m_iBottom=bottom;
	m_iRight=right;
	m_iLeft=left;
}

void CRect::Set(int top, int bottom, int left, int right)
{
	m_iTop=top;
	m_iBottom=bottom;
	m_iRight=right;
	m_iLeft=left;
}

CVGPtr<CRect> CRect::create()
{
	return(CVGPtr<CRect>(new CRect()));
}

CVGPtr<CRect> CRect::create(int top, int bottom, int left, int right)
{
	return(CVGPtr<CRect>(new CRect(top,bottom,left,right)));
}
