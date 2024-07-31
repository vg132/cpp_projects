#ifndef __A13C1EC971C0010BC1CC1__OBJECTDATA__HPP__
#define __A13C1EC971C0010BC1CC1__OBJECTDATA__HPP__

#include "vgptr.hpp"
#include "screenobject.hpp"
#include "point.hpp"

namespace vwf
{
	class CObjectData
	{
	private:
		CObjectData(CVGPtr<CScreenObject> object, CVGPtr<CRect> rect);

		CVGPtr<CScreenObject> m_Object;
		CVGPtr<CRect> m_Rect;
	public:
		static CVGPtr<CObjectData> create(CVGPtr<CScreenObject> object, CVGPtr<CRect> rect);

		CVGPtr<CScreenObject> GetObject(){return(m_Object);};
		CVGPtr<CRect> GetRect(){return(m_Rect);};

		~CObjectData(void);
	};
}

#endif // __A13C1EC971C0010BC1CC1__OBJECTDATA__HPP__
