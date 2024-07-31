// DSAddIn.h : header file
//

#if !defined(AFX_DSADDIN_H__27BF84C5_8EAC_445A_A583_A4B011A435B2__INCLUDED_)
#define AFX_DSADDIN_H__27BF84C5_8EAC_445A_A583_A4B011A435B2__INCLUDED_

#include "commands.h"

// {50FC7CED-A6DD-4B3D-9F24-7F34FD35B627}
DEFINE_GUID(CLSID_DSAddIn,
0x50fc7ced, 0xa6dd, 0x4b3d, 0x9f, 0x24, 0x7f, 0x34, 0xfd, 0x35, 0xb6, 0x27);

/////////////////////////////////////////////////////////////////////////////
// CDSAddIn

class CDSAddIn : 
	public IDSAddIn,
	public CComObjectRoot,
	public CComCoClass<CDSAddIn, &CLSID_DSAddIn>
{
public:
	DECLARE_REGISTRY(CDSAddIn, "DefineAddin.DSAddIn.1",
		"DEFINEADDIN Developer Studio Add-in", IDS_DEFINEADDIN_LONGNAME,
		THREADFLAGS_BOTH)

	CDSAddIn() {}
	BEGIN_COM_MAP(CDSAddIn)
		COM_INTERFACE_ENTRY(IDSAddIn)
	END_COM_MAP()
	DECLARE_NOT_AGGREGATABLE(CDSAddIn)

// IDSAddIns
public:
	STDMETHOD(OnConnection)(THIS_ IApplication* pApp, VARIANT_BOOL bFirstTime,
		long dwCookie, VARIANT_BOOL* OnConnection);
	STDMETHOD(OnDisconnection)(THIS_ VARIANT_BOOL bLastTime);

protected:
	CCommandsObj* m_pCommands;
	DWORD m_dwCookie;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DSADDIN_H__27BF84C5_8EAC_445A_A583_A4B011A435B2__INCLUDED)
