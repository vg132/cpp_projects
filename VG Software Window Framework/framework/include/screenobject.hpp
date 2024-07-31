#ifndef __17E011DB22A353A127560__SCREENOBJECT__HPP__
#define __17E011DB22A353A127560__SCREENOBJECT__HPP__

#include "rect.hpp"
#include "vgptr.hpp"
#include "terminal.h"

using namespace terminal_star85;

namespace vwf
{
	class CScreenObject
	{
	protected:
		CScreenObject(void);
		static terminal_star85::terminal m_Term;
		CVGPtr<CRect> m_Rect;
		bool m_bBorder;
		int m_iColor;
	public:
		static CVGPtr<CScreenObject> create();
		virtual void Show(CVGPtr<CRect> rect){};
		virtual void Hide(){};
		virtual bool RectInRect(CVGPtr<CRect> rect);

		virtual bool Enter(){return(false);};
		virtual void Leave(){};

		virtual bool HandleEvent(Event event, CVGPtr<CScreenObject> scrObj){return(false);};

		bool PointInRect(int x, int y);
		bool PointInRect(CVGPtr<CPoint> point);
		virtual ~CScreenObject(void);
	};
}


#endif // __17E011DB22A353A127560__SCREENOBJECT__HPP__
