#ifndef __117C78909EEED55D345C2__REPLAYDIRWATCHER__H__
#define __117C78909EEED55D345C2__REPLAYDIRWATCHER__H__

#include "directorychanges.h"

class CReplayDirWatcher : public CDirectoryChangeHandler
{
private:
	CString m_strReplayName;
	CString m_strHotlapName;
	CString m_strTmp;
public:
	CReplayDirWatcher(void);
	~CReplayDirWatcher(void);
protected:
	void On_FileModified(const CString &strFileName);
	void On_FileRemoved(const CString & strFileName);
};

#endif // __117C78909EEED55D345C2__REPLAYDIRWATCHER__H__
