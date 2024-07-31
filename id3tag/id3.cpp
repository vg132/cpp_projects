#include "id3.hpp"

using namespace std;

const char *id3_genres[148] =
{
	"Blues", "Classic Rock", "Country", "Dance", "Disco", "Funk", "Grunge", "Hip-Hop",
	"Jazz", "Metal", "New Age", "Oldies", "Other", "Pop", "R&B", "Rap", "Reggae",
	"Rock", "Techno", "Industrial", "Alternative", "Ska", "Death Metal", "Pranks", "Soundtrack",
	"Euro-Techno", "Ambient", "Trip-Hop", "Vocal", "Jazz+Funk", "Fusion", "Trance", "Classical",
	"Instrumental", "Acid", "House", "Game", "Sound Clip", "Gospel", "Noise", "Alt",
	"Bass", "Soul", "Punk", "Space", "Meditative", "Instrumental Pop",
	"Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "Techno-Industrial", "Electronic",
	"Pop-Folk", "Eurodance", "Dream", "Southern Rock", "Comedy", "Cult",
	"Gangsta Rap", "Top 40", "Christian Rap", "Pop/Funk", "Jungle", "Native American",
	"Cabaret", "New Wave", "Psychedelic", "Rave", "Showtunes", "Trailer", "Lo-Fi", "Tribal",
	"Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical", "Rock & Roll", "Hard Rock", "Folk",
	"Folk/Rock", "National Folk", "Swing", "Fast-Fusion", "Bebob", "Latin", "Revival",
	"Celtic", "Bluegrass", "Avantgarde", "Gothic Rock", "Progressive Rock",
	"Psychedelic Rock", "Symphonic Rock", "Slow Rock", "Big Band", "Chorus", "Easy Listening",
	"Acoustic", "Humour", "Speech", "Chanson", "Opera", "Chamber Music", "Sonata", "Symphony",
	"Booty Bass", "Primus", "Porn Groove", "Satire", "Slow Jam", "Club", "Tango",
	"Samba", "Folklore", "Ballad", "Power Ballad", "Rhythmic Soul", "Freestyle", "Duet",
	"Punk Rock", "Drum Solo", "A Cappella", "Euro-House", "Dance Hall", "Goa",
	"Drum & Bass", "Club-House", "Hardcore", "Terror", "Indie", "BritPop", "Negerpunk",
	"Polsk Punk", "Beat", "Christian Gangsta Rap", "Heavy Metal", "Black Metal", "Crossover",
	"Contemporary Christian", "Christian Rock", "Merengue", "Salsa", "Thrash Metal",
	"Anime", "JPop", "Synthpop"
};


CID3::CID3()
{
	myID3.album=NULL;
	myID3.band=NULL;
	myID3.comment=NULL;
	myID3.genre=NULL;
	myID3.title=NULL;
	myID3.year=NULL;
	myID3.ID3TAG=NULL;
	myID3.NEWID3=NULL;
	myID3.tracknum=NULL;
	myID3.header[0]='\0';
	myID3.dynbuffer=0;
	myID3.currsize=10;
	myID3.currpos=10;
	myID3.size=0;
	myID3.version=0;
	myID3.flags=0;
	myID3.footer=0;
	myID3.extended=0;
	myID3.experimental=0;
	myID3.ready = 1;
}

CID3::~CID3()
{
	Reset();
}

int CID3::CheckID3Version(ifstream *fin)
{
	char fBuffer[3];
	bool found1(false), found2(false);
	int rValue;

	fin->seekg(0,ios::beg);
	fin->read((char*)fBuffer,sizeof(char)*3);

	if(strstr(fBuffer, "ID3"))
		found2 = true;
	
	fin->seekg(-128,ios::end);
	fin->read((char*)fBuffer,sizeof(char)*3);

	if(strstr(fBuffer, "TAG"))
		found1 = true;

	rValue = ((found1 == true) && (found2 == true)) ? CID3::ID3_FOUNDBOTH : (found1 == true) ? CID3::ID3_FOUND1 : (found2 == true) ? CID3::ID3_FOUND2 : 0;
	myID3.version = ((found1 == true) && (found2 == true)) ? CID3::ID3_VERSION2 : (found1 == true) ? CID3::ID3_VERSION1 : (found2 == true) ? CID3::ID3_VERSION2 : 0;

	return(myID3.version);
}

int CID3::Reset()
{
	if(myID3.album!=NULL)
		delete[] myID3.album;
	if(myID3.band!=NULL)
		delete[] myID3.band;
	if(myID3.comment!=NULL)
		delete[] myID3.comment;
	if(myID3.genre!=NULL)
		delete[] myID3.genre;
	if(myID3.title!=NULL)
		delete[] myID3.title;
	if(myID3.year!=NULL)
		delete[] myID3.year;
	if(myID3.ID3TAG!=NULL)
		delete[] myID3.ID3TAG;
	if(myID3.NEWID3!=NULL)
		delete[] myID3.NEWID3;
	if(myID3.tracknum!=NULL)
		delete[] myID3.tracknum;

	myID3.album=NULL;
	myID3.band=NULL;
	myID3.comment=NULL;
	myID3.genre=NULL;
	myID3.title=NULL;
	myID3.year=NULL;
	myID3.ID3TAG=NULL;
	myID3.NEWID3=NULL;
	myID3.tracknum=NULL;

	myID3.header[0]='\0';
	myID3.dynbuffer=0;
	myID3.currsize=10;
	myID3.currpos=10;
	myID3.size=0;
	myID3.version=0;
	myID3.flags=0;
	myID3.footer=0;
	myID3.extended=0;
	myID3.experimental=0;
	myID3.ready = 1;
	return(0);
}

bool CID3::FrameIsNull(char *frame, int chars)
{
	bool IsNull(true);

	for(int x = 0; x < chars; x++)
		if(frame[x] != 0)
			IsNull = false;
	return(IsNull);
}

const char* CID3::GetGenre()
{
	if(myID3.version==CID3::ID3_VERSION1)
	{
		if((myID3.genre[0]>=0)&&(myID3.genre[0]<=(signed char)148))
			return(id3_genres[myID3.genre[0]]);
		else
			return("\0");
	}
	else
	{
		return(myID3.genre);
	}
}

int CID3::LoadID3(char *filepath)
{
	Reset();
	char tmpHeader[10],tmp[3];
	ifstream fin;
	fin.open(filepath,ios::in);
	CheckID3Version(&fin);
	fin.seekg(0,ios::beg);
	switch(myID3.version)
	{
		case CID3::ID3_VERSION2:
			fin.read((char*)&myID3.header,sizeof(char)*10);
			if(!strstr(myID3.header, "ID3"))
			{
				fin.close();
				return(-1);
			}
			tmpHeader[0] = '\0';
			myID3.size=GetFourByteSyncSafe(myID3.header[6], myID3.header[7], myID3.header[8], myID3.header[9]);
			myID3.flags=(myID3.header[6] & 255);
			myID3.footer=ExtractBits(myID3.flags, 5, 1);
			myID3.extended=ExtractBits(myID3.flags, 7, 1);
			myID3.experimental=ExtractBits(myID3.flags, 6, 1);
			myID3.ID3TAG=new char[myID3.size-(myID3.footer * 10)];

			fin.seekg(0,ios::beg);
			fin.read(myID3.ID3TAG,sizeof(char)*(myID3.size-(myID3.footer*10)));

			memcpy(tmpHeader,myID3.ID3TAG,10);

			myID3.album=RetrField("TALB");
			myID3.band=RetrField("TPE1");
			myID3.comment=RetrField("COMM");
			myID3.genre=RetrField("TCON");
			myID3.title=RetrField("TIT2");
			myID3.tracknum=RetrField("TRCK");
			myID3.year=RetrField("TYER");

			if(myID3.comment[5]>0)
				strcpy(&myID3.comment[0], &myID3.comment[5]);
			break;
		case CID3::ID3_VERSION1:

			fin.seekg(-128,ios::end);
			fin.read((char*)&myID3.header,sizeof(char)*3);

			if(!strstr(myID3.header, "TAG"))
			{
				fin.close();
				return(-1);
			}

			myID3.album=new char[31];
			myID3.band=new char[31];
			myID3.comment=new char[29];
			myID3.genre=new char[2];
			myID3.title=new char[31];
			myID3.year=new char[5];
			myID3.tracknum=new char[3];

			fin.read((char*)myID3.title,sizeof(char)*30);
			fin.read((char*)myID3.band,sizeof(char)*30);
			fin.read((char*)myID3.album,sizeof(char)*30);
			fin.read((char*)myID3.year,sizeof(char)*4);
			fin.read((char*)myID3.comment,sizeof(char)*28);
			fin.read((char*)myID3.tracknum,sizeof(char)*2);
			if(myID3.tracknum[0]=='\0')
			{
				IntToChar(myID3.tracknum[1],tmp);
				strcpy(myID3.tracknum,tmp);
			}
			else
			{
				myID3.tracknum[0]='\0';
			}
			fin.read((char*)myID3.genre,sizeof(char));

			myID3.album[29] = '\0';
			myID3.band[29] = '\0';
			myID3.comment[28] = '\0';
			myID3.genre[1] = '\0';
			myID3.title[29] = '\0';
			myID3.year[4] = '\0';
			break;
		default:
			fin.close();
			return(-1);
	}
	fin.close();
	return(0);
}

char* CID3::RetrField(char *identifier)
{
	if((myID3.version != CID3::ID3_VERSION2) || (IsPrimed() == 0))
		return(0);

	char *dest;
	char tmpHeader[10];
	int framesize = 0, pos = 0;

	tmpHeader[0] = '\0';

	memcpy(tmpHeader,myID3.ID3TAG,10);

	while(!FrameIsNull(tmpHeader, 10))
	{
		pos += 10;
		framesize = GetFourByteSyncSafe(tmpHeader[4], tmpHeader[5], tmpHeader[6], tmpHeader[7]);

		if(strstr(tmpHeader, identifier))
		{
			dest=new char[framesize+1];
			dest[framesize]='\0';
			memcpy(dest,&myID3.ID3TAG[pos+1],framesize-1);
			dest[framesize-1]='\0';
			return(dest);
		}
		pos += framesize;
		if(pos>myID3.size)
			break;
		memcpy(tmpHeader,&myID3.ID3TAG[pos],10);
	}
	dest=new char[1];
	dest[0]='\0';
	return(dest);
}

void CID3::IntToChar(int n, char* s)
{
	int i, sign;
	if((sign=n)<0)
		n=-n;
	i=0;
	do
	{
		s[i++]=n%10+'0';
	}while((n/=10)>0);
	if(sign<0)
		s[i++]='-';
	s[i]='\0';
	char *tmp;
	tmp=StrRev(s);
	strcpy(s,tmp);
	delete[] tmp;
}

char* CID3::StrRev(char *s)
{
	char *tmp=new char[strlen(s)+1];
	for(int i=strlen(s)-1;i>=0;i--)
		tmp[strlen(s)-i-1]=s[i];
	tmp[strlen(s)]='\0';
	return(tmp);
}
