#ifndef __58A2A2F7A53D16E94992E__ACTIVE__HPP__
#define __58A2A2F7A53D16E94992E__ACTIVE__HPP__

#include <list>
#include <algorithm>
#include <iterator>
#include <functional>

#include "screenobject.hpp"
#include "vgptr.hpp"
#include "actionbase.hpp"
#include "actionhelp.hpp"

namespace vwf
{
	class CActive : public CScreenObject
	{
	private:
		void Handle(CVGPtr<CActionBase> action, Event event);
	protected:
		CActive(void);

		std::list<CVGPtr<CActionBase> > m_Actions;
		std::list<CVGPtr<CActionBase> >::iterator m_ActionIter;
	public:
		static CVGPtr<CActive> create();

		virtual bool HandleEvent(Event event, CVGPtr<CScreenObject> scrObj);
		virtual void AddAction(CVGPtr<CActionBase> action);
		virtual void RemoveAction(CVGPtr<CActionBase> action);

		virtual ~CActive(void);
	};
}

#endif // __58A2A2F7A53D16E94992E__ACTIVE__HPP__
