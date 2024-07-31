#ifndef __BAB55DEA846C9FFD5B0C__SIZE__HPP__
#define __BAB55DEA846C9FFD5B0C__SIZE__HPP__

#include "vgptr.hpp"

namespace vwf
{
	class CSize
	{
	private:
		int m_iWidth;
		int m_iHeight;
		CSize(int width,int height);
	public:
		static CVGPtr<CSize> create(int width, int height);

		inline int GetWidth(){return(m_iWidth);};
		inline int GetHeight(){return(m_iHeight);};

		~CSize(void);
	};
}

#endif // __BAB55DEA846C9FFD5B0C__SIZE__HPP__
