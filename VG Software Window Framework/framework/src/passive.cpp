#include "passive.hpp"

using namespace vwf;

CPassive::CPassive(void):
	CScreenObject()
{
}

CPassive::~CPassive(void)
{
}

CVGPtr<CPassive> CPassive::create()
{
	return(CVGPtr<CPassive>(new CPassive()));
}
