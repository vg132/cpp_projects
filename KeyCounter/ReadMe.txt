Time: 60-80 with program lookup, 30-40 without program lookup.

SYSTEMTIME sysTime1, sysTime2;
GetSystemTime(&sysTime1);
GetSystemTime(&sysTime2);
sprintf(m_Buffer,"Time: %d",sysTime2.wMilliseconds-sysTime1.wMilliseconds);
SetWindowText(m_hWnd,m_Buffer);