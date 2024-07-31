// ViperTime.h: interface for the CViperTime class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIPERTIME_H__412C42C3_A038_11D5_95DD_00B0D064C66D__INCLUDED_)
#define AFX_VIPERTIME_H__412C42C3_A038_11D5_95DD_00B0D064C66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream.h>
#include <fstream.h>


class CViperTime : public CTime
{
public:
	CViperTime();
	virtual ~CViperTime();

	friend ofstream & operator<<(ofstream & fos, CViperTime & time);
};

#endif // !defined(AFX_VIPERTIME_H__412C42C3_A038_11D5_95DD_00B0D064C66D__INCLUDED_)
