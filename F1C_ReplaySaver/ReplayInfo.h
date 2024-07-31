#ifndef __93D4DB6335E3104F5FFBF3__REPLAYINFO__H__
#define __93D4DB6335E3104F5FFBF3__REPLAYINFO__H__

class CReplayInfo
{
private:
	char *m_pName;
	char *m_pReplayDirectory;
	char *m_pExecutable;
	char *m_pStartupDirectory;
public:
	void SetName(char *name);
	char* GetName(){return(m_pName);};
	void SetReplayDirectory(char *replay_directory);
	char* GetReplayDirecotry(){return(m_pReplayDirectory);};
	void SetExecutable(char *executable);
	char* GetExecutable(){return(m_pExecutable);};
	void SetStartupDirectory(char *startup_directory);
	char* GetStartupDirectory(){return(m_pStartupDirectory);};
	CReplayInfo(void);
	~CReplayInfo(void);
};

#endif // __93D4DB6335E3104F5FFBF3__REPLAYINFO__H__
