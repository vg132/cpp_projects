#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

void MorseToText_viktor(const char *pSrc, char *pDst)
{
	const char* pLast(pSrc--);
	pDst--;
	while(true)
	{
		if((*(++pSrc)==' ')||(!*pSrc))
		{
			if(*pLast=='.')
			{
				if(*(++pLast)=='.')
				{
					if(*(++pLast)=='.')
					{
						if(*(++pLast)=='.')
						{
							if(*(++pLast)=='-')
								*(++pDst)='4';
							else if(*pLast=='.')
								*(++pDst)='5';
							else
								*(++pDst)='H';
						}
						else if(*pLast=='-')
						{
							if(*(++pLast)=='-')
								*(++pDst)='3';
							else
								*(++pDst)='V';
						}
						else
						{
							*(++pDst)='S';
						}
					}
					else if(*pLast=='-')
					{
						if(*(++pLast)=='-')
							*(++pDst)='2';
						else if(*pLast=='.')
							*(++pDst)='F';
						else
							*(++pDst)='U';
					}
					else
					{
						*(++pDst)='I';
					}
				}
				else if(*pLast=='-')
				{
					if(*(++pLast)=='.')
					{
						if(*(++pLast)=='.')
						{
							*(++pDst)='L';
						}
						else if(*pLast=='-')
						{
							*(++pDst)='.';
						}
						else
						{
							*(++pDst)='R';
						}
					}
					else if(*pLast=='-')
					{
						if(*(++pLast)=='.')
						{
							*(++pDst)='P';
						}
						else if(*pLast=='-')
						{
							if(*(++pLast)=='-')
								*(++pDst)='1';
							else
								*(++pDst)='J';
						}
						else
						{
							*(++pDst)='W';
						}
					}
					else
					{
						*(++pDst)='A';
					}
				}
				else
				{
					*(++pDst)='E';
				}
			}
			else
			{
				if(*(++pLast)=='-')
				{
					if(*(++pLast)=='.')
					{
						if(*(++pLast)=='.')
						{
							if(*(++pLast)=='.')
							{
								*(++pDst)='7';
							}
							else if(*pLast=='-')
							{
								*(++pDst)=',';
							}
							else
							{
								*(++pDst)='Z';
							}
						}
						else if(*pLast=='-')
						{
							*(++pDst)='Q';
						}
						else
						{
							*(++pDst)='G';
						}
					}
					else if(*pLast=='-')
					{
						if(*(++pLast)=='.')
						{
							*(++pDst)='8';
						}
						else if(*pLast=='-')
						{
							if(*(++pLast)=='.')
								*(++pDst)='9';
							else
								*(++pDst)='0';
						}
						else
						{
							*(++pDst)='O';
						}
					}
					else
					{
						*(++pDst)='M';
					}
				}
				else if(*pLast=='.')
				{
					if(*(++pLast)=='.')
					{
						if(*(++pLast)=='.')
						{
							if(*(++pLast)=='.')
								*(++pDst)='6';
							else
								*(++pDst)='B';
						}
						else if(*pLast=='-')
						{
							*(++pDst)='X';
						}
						else
						{
							*(++pDst)='D';
						}
					}
					else if(*pLast=='-')
					{
						if(*(++pLast)=='.')
							*(++pDst)='C';
						else if(*pLast=='-')
							*(++pDst)='Y';
						else
							*(++pDst)='K';
					}
					else
					{
						*(++pDst)='N';
					}
				}
				else
				{
					*(++pDst)='T';
				}
			}
			if(*pSrc)
			{
				if(*(pLast=++pSrc)==' ')
				{
					*(++pDst)=*pLast;
					pLast=pSrc+=2;
				}
			}
			else
			{
				break;
			}
		}
	}
}

typedef __int64 int64;

extern "C" // so we don't have to include that basterd windows.h
{
    int __stdcall QueryPerformanceCounter(int64 *lpPerformanceCount);
    int __stdcall QueryPerformanceFrequency(int64 *lpFrequency);
}

//
// time functions
//
int64 GetTickFrequency()
{
    int64 Freq;
    QueryPerformanceFrequency(&Freq);
    return Freq;
}

int64 GetTickCount()
{
    int64 Count;
    QueryPerformanceCounter(&Count);
    return Count;
}


//
// data
//
char *g_pVerifyData = 0;
char *g_pTestData = 0;
char *g_pDstData = 0;
int g_TestDataSize, g_VerifyDataSize;

int LoadFileAsString(const char *pFilename, char **pPtr)
{
    FILE *pInput = fopen(pFilename, "rb");

    // get size
    fseek(pInput, 0, SEEK_END);
    int size = ftell(pInput);
    fseek(pInput, 0, SEEK_SET);

    // allocade and read
    *pPtr = new char[size+1];
    fread(*pPtr, 1, size, pInput);
    (*pPtr)[size] = 0;

    // close and return size
    fclose(pInput);
    return size;
}

void LoadTestData()
{
    g_TestDataSize = LoadFileAsString("c:\\temp\\morse\\morse.txt", &g_pTestData);
    g_pDstData = new char[g_TestDataSize];
    g_VerifyDataSize = LoadFileAsString("c:\\temp\\morse\\source.txt", &g_pVerifyData);
}

//
// Test function
//
void Test(const char *pName, void (*pfnFunc)(const char *, char *))
{
    printf("%15s   ", pName);
    int64 BestTime = GetTickCount();
    for(int i = 0; i < 10; i++)
    {
        int64 time = GetTickCount();
        pfnFunc(g_pTestData, g_pDstData);
        time = GetTickCount()-time;

        if(BestTime == -1 || BestTime > time)
            BestTime = time;
    }

    printf("%f ms   ", (float)((BestTime/(double)GetTickFrequency())*1000));

    if(memcmp(g_pDstData, g_pVerifyData, g_VerifyDataSize) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");
}

//
int main()
{
		LoadTestData();

    // run tests
    Test("Don Tomaso", MorseToText_Don_Tomaso);




    // clean up
    delete [] g_pVerifyData;
    delete [] g_pDstData;
    delete [] g_pTestData;

    system("pause");
    return 0;
}










