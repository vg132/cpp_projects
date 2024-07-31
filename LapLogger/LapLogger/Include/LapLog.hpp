#ifndef _LAP_LOG_HPP
#define _LAP_LOG_HPP

#include <windows.h>
#include <string>
#include <stdio.h>
#include <tchar.h>

#include "InternalsPlugin.hpp"
#include "Session.hpp"
#include "Net.hpp"

// This is used for app to find out information about the plugin
class InternalsPluginInfo : public PluginObjectInfo
{
 public:

  // Constructor/destructor
  InternalsPluginInfo();
  ~InternalsPluginInfo() {}

  // Derived from base class PluginObjectInfo
  virtual const char*    GetName()     const;
  virtual const char*    GetFullName() const;
  virtual const char*    GetDesc()     const;
  virtual const unsigned GetType()     const;
  virtual const char*    GetSubType()  const;
  virtual const unsigned GetVersion()  const;
  virtual void*          Create() const;

 private:

  char m_szFullName[128];
};


// This is used for the app to use the plugin for its intended purpose
class LapLog : public InternalsPluginV3
{
protected:
	const static char m_szName[];
	const static char m_szSubType[];
	const static unsigned m_uID;
	const static unsigned m_uVersion;

public:
	// Constructor/destructor
	LapLog() {}
	~LapLog() {}

	// Called from class InternalsPluginInfo to return specific information about plugin
	static const char *   GetName()                     { return m_szName; }
	static const unsigned GetType()                     { return PO_INTERNALS; }
	static const char *   GetSubType()                  { return m_szSubType; }
	static const unsigned GetVersion()                  { return m_uVersion; }

	// Derived from base class PluginObject
	void                  Destroy()                     { Shutdown(); }  // poorly named ... doesn't destroy anything
	PluginObjectInfo *    GetInfo();
	unsigned              GetPropertyCount() const      { return 0; }
	PluginObjectProperty *GetProperty( const char * )   { return 0; }
	PluginObjectProperty *GetProperty( const unsigned ) { return 0; }

	// These are the functions derived from base class InternalsPlugin
	// that can be implemented.
	void Startup();         // game startup
	void Shutdown();        // game shutdown

	void StartSession();    // session has started
	void EndSession();      // session has ended
	
	// SCORING OUTPUT
	bool WantsScoringUpdates() { return( true ); } // CHANGE TO TRUE TO ENABLE SCORING EXAMPLE!
	void UpdateScoring( const ScoringInfoV2 &info );

private:
	CSession _session;
};


#endif // _LAP_LOG_HPP