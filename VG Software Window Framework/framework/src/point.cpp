#include "point.hpp"

using namespace vwf;

CPoint::CPoint(int x, int y)
{
	m_iX=x;
	m_iY=y;
}

CPoint::~CPoint(void)
{
}

CVGPtr<CPoint> CPoint::create(int x, int y)
{
	return(CVGPtr<CPoint>(new CPoint(x,y)));
}

CVGPtr<CPoint> CPoint::create()
{
	return(CVGPtr<CPoint>(new CPoint()));
}
