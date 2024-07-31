#ifndef __FB74907184306D099CAF5__RECT__HPP__
#define __FB74907184306D099CAF5__RECT__HPP__

#include "point.hpp"
#include "vgptr.hpp"

namespace vwf
{
	class CRect
	{
	private:
		CRect();
		CRect(int top, int bottom, int left, int right);
		int m_iTop, m_iBottom, m_iLeft, m_iRight;
	public:
		static CVGPtr<CRect> create(int top, int bottom, int left, int right);
		static CVGPtr<CRect> create();
		~CRect(){};

		inline int GetTop(){return(m_iTop);};
		inline int GetBottom(){return(m_iBottom);};
		inline int GetLeft(){return(m_iLeft);};
		inline int GetRight(){return(m_iRight);};

		inline void SetTop(int top){m_iTop=top;};
		inline void SetBottom(int bottom){m_iBottom=bottom;};
		inline void SetLeft(int left){m_iLeft=left;};
		inline void SetRight(int right){m_iRight=right;};

		void Set(int top, int bottom, int left, int right);
	};
}

#endif // __FB74907184306D099CAF5__RECT__HPP__
