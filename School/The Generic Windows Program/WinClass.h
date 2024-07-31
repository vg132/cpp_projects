#ifndef __WINCLASS__H__
#define __WINCLASS__H__

class WinClass : public WinSimpleClass
{
public:
	WinClass(char const* className, HINSTANCE hInst, WNDPROC wndProc);
	WinClass(int resId, HINSTANCE hInst, WNDPROC wndProc);
	void SetBgSysColor(int sysColor){_class.hbrBackground=reinterpret_cast<HBRUSH>(sysColor+1);}
	void SetResIcons(int resId);
	void Register();
protected:
	void SetDefaults();
	WNDCLASSEX _class;
};

#endif