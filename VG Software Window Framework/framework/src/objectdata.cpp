#include "objectdata.hpp"

using namespace vwf;

CObjectData::CObjectData(CVGPtr<CScreenObject> object, CVGPtr<CRect> rect)
{
	m_Object=object;
	m_Rect=rect;
}

CObjectData::~CObjectData(void)
{
}

CVGPtr<CObjectData> CObjectData::create(CVGPtr<CScreenObject> object, CVGPtr<CRect> rect)
{
	return(CVGPtr<CObjectData>(new CObjectData(object,rect)));
}
