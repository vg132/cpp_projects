#ifndef __BB1A34F6F14674545A13CD__ACTIONBASE__HPP__
#define __BB1A34F6F14674545A13CD__ACTIONBASE__HPP__

#include "vgptr.hpp"
#include "screenobject.hpp"

namespace vwf
{
	class CActionBase
	{
	protected:
		Event m_Event;
	public:
		virtual void Perform(CVGPtr<CScreenObject> scrObj){};
		Event GetEvent(){return(m_Event);};
		virtual bool Handle(Event event){return(event.what==m_Event.what);};

		CActionBase(void);
		virtual ~CActionBase(void);
	};
}

#endif // __BB1A34F6F14674545A13CD__ACTIONBASE__HPP__
