#ifndef __834B938E2BE59A9C7BC3D__ACTIONHELP__H__
#define __834B938E2BE59A9C7BC3D__ACTIONHELP__H__

namespace vwf
{
	class CActionHelp
	{
	private:
		Event m_Event;
	public:
		CActionHelp(Event event){m_Event=event;};
		bool operator()(CVGPtr<CActionBase> &ab) const {return(ab->Handle(m_Event));};
	};
}

#endif // __834B938E2BE59A9C7BC3D__ACTIONHELP__H__
