#include "../include/Crypt.hpp"

BYTE* Crypt::Encrypt(BYTE* pbJamData, int nNumBytes)
{
	BYTE *outputData=new BYTE[nNumBytes];
	unsigned long *ptr=(unsigned long*)outputData;
	unsigned long *pBlocks = (unsigned long *)pbJamData;
	unsigned long lPattern = 0xB082F165;

	for (int nNumBlocks = nNumBytes / 4; nNumBlocks > 0; pBlocks++, ptr++,nNumBlocks--)
	{
		*ptr = *pBlocks ^ lPattern;
		lPattern *= 5;
	}
	return outputData;
}

