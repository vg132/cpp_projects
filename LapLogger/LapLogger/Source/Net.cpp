#include "../include/Net.hpp"

CNet::CNet()
{
}

CNet::~CNet()
{
}

void CNet::PadRight(std::string *str)
{
	while(str->length()%4)
	{
		str->append(" ");
	}
}

void __cdecl CNet::SendData(LPVOID iValue)
{
	Crypt crypt;
	std::string *paramData=(std::string*)iValue;

	PadRight(paramData);
	BYTE *buffer32=new BYTE[paramData->size()];
	for(std::string::size_type i=0;i<paramData->size();++i)
	{
		buffer32[i]=(BYTE)((std::string)*paramData)[i];
	}
	BYTE* tmp5=crypt.Encrypt(buffer32,paramData->size());

	DWORD dwBytesWritten = 0;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL, hConnect = NULL, hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
	
	// Specify an HTTP server.
	if(hSession)
	{
		hConnect = WinHttpConnect(hSession, L"localhost", /*INTERNET_DEFAULT_HTTP_PORT*/1579, 0);
	}

	// Create an HTTP Request handle.
	if(hConnect)
	{
		hRequest = WinHttpOpenRequest(hConnect, L"POST",  L"/Default.aspx", NULL, WINHTTP_NO_REFERER,  WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
	}

	if(hRequest)
	{
		bResults=WinHttpAddRequestHeaders(hRequest,L"Content-Type: application/x-www-form-urlencoded",-1,WINHTTP_ADDREQ_FLAG_ADD);
	}

	// Send a Request.
	if(hRequest)
	{
		bResults = WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, paramData->length(), 0);
	}

	// Write data to the server.
	if(bResults)
	{
		bResults = WinHttpWriteData(hRequest, tmp5, paramData->size(), &dwBytesWritten);
	}

	// End the request.
	if(bResults)
	{
		bResults = WinHttpReceiveResponse(hRequest, NULL);
	}

	// Report any errors.
	if (!bResults)
	{
		printf("Error %d has occurred.\n",GetLastError());
	}

	// Close any open handles.
	if(hRequest)
	{
		WinHttpCloseHandle(hRequest);
	}
	if(hConnect)
	{
		WinHttpCloseHandle(hConnect);
	}
	if(hSession)
	{
		WinHttpCloseHandle(hSession);
	}
}
