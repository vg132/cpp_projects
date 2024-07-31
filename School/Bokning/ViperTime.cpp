// ViperTime.cpp: implementation of the CViperTime class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bokning.h"
#include "ViperTime.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CViperTime::CViperTime()
{

}

CViperTime::~CViperTime()
{

}

ofstream & operator<<(ofstream & fos, CViperTime & time)
{
	fos << time.GetDay();
	return(fos);
}
