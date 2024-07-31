#include "active.hpp"

using namespace vwf;
using namespace std;

CActive::CActive(void):
	CScreenObject()
{
}

CActive::~CActive(void)
{
}

CVGPtr<CActive> CActive::create()
{
	return(CVGPtr<CActive>(new CActive()));
}

void CActive::AddAction(CVGPtr<CActionBase> action)
{
	m_Actions.push_back(action);
}

void CActive::RemoveAction(CVGPtr<CActionBase> action)
{
	m_ActionIter=find(m_Actions.begin(),m_Actions.end(),action);
	if(m_ActionIter!=m_Actions.end())
		m_Actions.erase(m_ActionIter);
}

bool CActive::HandleEvent(Event event, CVGPtr<CScreenObject> scrObj)
{
	m_ActionIter=find_if(m_Actions.begin(),m_Actions.end(),CActionHelp(event));
	if(m_ActionIter!=m_Actions.end())
	{
		(*m_ActionIter)->Perform(scrObj);
		return(true);
	}
	return(false);
}
