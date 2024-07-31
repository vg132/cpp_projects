#ifndef __WINEXCEPTION__H__
#define __WINEXCEPTION__H__

class WinException
{
public:
	WinException(char* msg):_err(::GetLastError()), _msg(msg){}
	DWORD GetError() const {return(_err);}
	char const* GetMessage() const{return(_msg);}
private:
	DWORD _err;
	char* _msg;
};

#endif