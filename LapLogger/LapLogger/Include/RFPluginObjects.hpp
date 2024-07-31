#ifndef _PLUGINOBJECT
#define _PLUGINOBJECT

#include <windows.h>

class PluginObjectInfo;

typedef const char* (__cdecl *GETPLUGINNAME)();
typedef unsigned (__cdecl *GETPLUGINVERSION)();
typedef unsigned (__cdecl *GETPLUGINOBJECTCOUNT)();
typedef PluginObjectInfo* (__cdecl *GETPLUGINOBJECTINFO)(const unsigned uIndex);
typedef PluginObjectInfo* (__cdecl *GETPLUGINOBJECTINFO)(const unsigned uIndex);
typedef float (__cdecl *GETPLUGINSYSTEMVERSION) ();

//plugin object types
enum PluginObjectType
{
  PO_VIDEO_EXPORT = 0x00000001,
  PO_RFMODIFIER   = 0x00000002,
  PO_HWPLUGIN     = 0x00000003,
  PO_GAMESTATS    = 0x00000004,
  PO_NCPLUGIN     = 0x00000005,
  PO_MOTION       = 0x00000006,
  PO_IRCPLUGIN    = 0x00000007,
  PO_IVIBE        = 0x00000008,
  PO_INTERNALS    = 0x00000009,
};

enum POPType
{
  POPTYPE_INT,
  POPTYPE_FLOAT,
  POPTYPE_STRING,
};

static char POPTypeNames[3][64] = 
{
  "POPTYPE_INT",
  "POPTYPE_FLOAT",
  "POPTYPE_STRING",
};

const unsigned POP_MAXNAME = 32;
const unsigned POP_MAXDESC = 256;

struct PluginObjectProperty
{
  union
  {
    int   iValue;
    float fValue;
    char* szValue;
  };

  POPType uPropertyType;
  char szName[POP_MAXNAME];
  char szDesc[POP_MAXDESC];
};

class PluginObject
{
public:
  PluginObject() {}
  virtual ~PluginObject(){};
  virtual void Destroy()=0;
  virtual class PluginObjectInfo* GetInfo()=0;

  virtual unsigned GetPropertyCount() const =0;
  virtual PluginObjectProperty* GetProperty(const unsigned uIndex) =0;
  virtual PluginObjectProperty* GetProperty(const char* szName) =0;
};

class PluginObjectInfo
{
public:
  virtual ~PluginObjectInfo() {};
  virtual const char* GetName() const = 0;
  virtual const char* GetFullName() const = 0;
  virtual const char* GetDesc() const = 0;
  virtual const unsigned GetType() const = 0;
  virtual const char* GetSubType() const = 0;
  virtual const unsigned GetVersion() const = 0;
  virtual void* Create() const = 0;
};

#endif