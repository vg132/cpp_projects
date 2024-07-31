#ifndef __6DFA7233F416693CC73FE__ACTION__HPP__
#define __6DFA7233F416693CC73FE__ACTION__HPP__

#include "terminal.h"
#include "screenobject.hpp"
#include "vgptr.hpp"
#include "actionbase.hpp"

using namespace terminal_star85;

namespace vwf
{
	template <class TYPE>
	class CAction : public CActionBase
	{
	private:
		typedef void (TYPE::*ActionFunc)(Event event, CVGPtr<CScreenObject> scrObj);
		CAction(TYPE *t, ActionFunc func, Event event);
		ActionFunc m_Func;
		TYPE m_This;
	public:
		static CVGPtr<CAction<TYPE> > create(TYPE *t, ActionFunc func, Event event);
		void Perform(CVGPtr<CScreenObject> scrObj);
	};

	template <class TYPE>
	CAction<TYPE>::CAction(TYPE *t, ActionFunc func, Event event)
	{
		m_This=*t;
		m_Func=func;
		m_Event=event;
	}

	template <class TYPE>
	CVGPtr<CAction<TYPE> > CAction<TYPE>::create(TYPE *t, ActionFunc func, Event event)
	{
		return(CVGPtr<CAction<TYPE> >(new CAction<TYPE>(t,func,event)));
	}

	template <class TYPE>
	void CAction<TYPE>::Perform(CVGPtr<CScreenObject> scrObj)
	{
		(m_This.*m_Func)(m_Event,scrObj);
	}
}
#endif // __6DFA7233F416693CC73FE__ACTION__HPP__
