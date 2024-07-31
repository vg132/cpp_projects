#include "size.hpp"

using namespace vwf;

CSize::CSize(int width, int height)
{
	m_iWidth=width;
	m_iHeight=height;
}

CSize::~CSize(void)
{
}

CVGPtr<CSize> CSize::create(int width, int height)
{
	return(CVGPtr<CSize>(new CSize(width,height)));
}
