#ifndef __6BE5BA119DCD02151C24A__POINT__HPP__
#define __6BE5BA119DCD02151C24A__POINT__HPP__

#include "vgptr.hpp"

namespace vwf
{
	class CPoint
	{
	private:
		CPoint(){};
		CPoint(int x, int y);
		int m_iX,m_iY;
	public:
		static CVGPtr<CPoint> create();
		static CVGPtr<CPoint> create(int x, int y);
		inline int GetX(){return(m_iX);};
		inline int GetY(){return(m_iY);};
		inline void SetX(int x){m_iX=x;};
		inline void SetY(int y){m_iY=y;};
		~CPoint(void);
	};
}

#endif // __6BE5BA119DCD02151C24A__POINT__HPP__
