// 2004-07-08
// Easy ID3 reading class for C++. Tested with Visual C++ 2003 and g++2.96 (Redhat 7.3)
//
// This class is based on Brad Zasada's (brad@bradsoft.net) ID3 class.
//

#ifndef __141412203B91B22179977__ID3__HPP__
#define __141412203B91B22179977__ID3__HPP__

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#define ExtractBits(value, start, length) ((value >> (start - 1)) & ((1 << length) - 1))
#define GetFourByteSyncSafe(value1, value2, value3, value4) (((value1 & 255) << 21) | ((value2 & 255) << 14) | ((value3 & 255) << 7) | (value4 & 255))
#define CreateFourByteField(value1, value2, value3, value4) (((value1 & 255) << 24) | ((value2 & 255) << 16) | ((value3 & 255) << 8) | (value4 & 255))

struct ID3Struct
{
	char* band;
	char* album;
	char* title;
	char* comment;
	char* genre;
	char* year;
	char* ID3TAG;
	char* NEWID3;
	char* tracknum;
	char header[10];
	int currsize;
	int currpos;
	int size;
	int version;
	int ready;
	int dynbuffer;
	int	footer, extended, experimental;
	long flags;
};

class CID3
{
private:
	int CheckID3Version(std::ifstream *fin);
	char* RetrField(char* identifier);
	bool FrameIsNull(char* frame, int chars);
	int IsPrimed(){return(myID3.ready);};
	void IntToChar(int n, char* s);
	char* StrRev(char *s);
	int Reset();
	ID3Struct myID3;
public:
	static const int ID3_VERSION2=19990;
	static const int ID3_VERSION1=12000;
	static const int ID3_FOUND1=13000;
	static const int ID3_FOUND2=14000;
	static const int ID3_FOUNDBOTH=15000;

	const char* GetArtist(){return(myID3.band);};
	const char* GetTrackTitle(){return(myID3.title);};
	const char* GetTrackNum(){return(myID3.tracknum);};
	const char* GetAlbum(){return(myID3.album);};
	const char* GetYear(){return(myID3.year);};
	const char* GetComments(){return(myID3.comment);};
	const char* GetGenre();
	char GetGenreValue(){return(myID3.genre[0]);};
	int LoadID3(char* filepath);

	CID3();
	~CID3();
};

#endif // __141412203B91B22179977__ID3__HPP__
