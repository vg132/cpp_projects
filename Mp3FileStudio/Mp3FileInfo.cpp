#include "stdafx.h"
#include "Mp3FileInfo.h"

char* mpeg_version[]={"MPEG Version 2.5","reserved","MPEG Version 2.0","MPEG Version 1.0"};
char* layer[]={"Reserved","Layer 3","Layer 2","Layer 1"};
char* emphasis[]={"None","50/15 ms","reserved","CCIT J.17"};
char* yesno[]={"No","Yes"};
char* crc[]={"Yes","No"};
char* channel_mode[]={"Stereo","Joint Stereo","Dual channel (2 mono channels)","Single channel (Mono)"};

int bit_rate[2][3][15]={
												{
													{0,32,64,96,128,160,192,224,256,288,320,352,384,416,448},
													{0,32,48,56,64,80,96,112,128,160,192,224,256,320,384},
													{0,32,40,48,56,64,80,96,112,128,160,192,224,256,320}
												},
												{
													{0,32,48,56,64,80,96,112,128,144,160,176,192,224,256},
													{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160},
													{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160}
												}
											};
int frequency[3][4]={
											{
												{44100},{48000},{32000},{0},
											},
											{
												{22050},{24000},{16000},{0},
											},
											{
												{11025},{12000},{8000},{0},
											}
										};


CMp3FileInfo::CMp3FileInfo()
{

}

CMp3FileInfo::~CMp3FileInfo()
{
}


bool CMp3FileInfo::GetMP3Info(CString file)
{
	char *tag;
	m_FileName=file;
	CFile f;
	//Open File and save file size
	if(f.Open(m_FileName,CFile::modeRead|CFile::shareExclusive,NULL))
	{
		tag = new char[4];
		m_FileSize=f.GetLength();
		// Read MP3 Frame Header
		f.SeekToBegin();
		f.Read((char*)&m_FrameHeader,sizeof(m_FrameHeader));
		//Read MP3 Tag Info
		f.Seek(-128,CFile::end);
		f.Read((char*)&m_Tag,sizeof(m_Tag));
		f.Close();
		//Check if its a valid MP3 Tag
		strncpy(tag,(char*)&m_Tag.TAG,3);
		tag[3]='\0';
		if(strcmp(tag,"TAG"))
			return(false);

		//Read Frame Header Info
		m_FrameHeaderInfo.mpeg_version = (m_FrameHeader.byte2 & 24) >> 3;
		m_FrameHeaderInfo.layer = (m_FrameHeader.byte2 & 6) >> 1;
		m_FrameHeaderInfo.crc = (m_FrameHeader.byte2 & 1);
		m_FrameHeaderInfo.bitrate =  (m_FrameHeader.byte3 & 240) >> 4;
		m_FrameHeaderInfo.frequency = (m_FrameHeader.byte3 & 12) >> 2;
		m_FrameHeaderInfo.padding = (m_FrameHeader.byte3 & 2) >> 1;
		m_FrameHeaderInfo.private_bit = (m_FrameHeader.byte3 & 1);
		m_FrameHeaderInfo.channel_mode = (m_FrameHeader.byte4 & 192) >> 6;
		m_FrameHeaderInfo.mode_extension = (m_FrameHeader.byte4 & 48) >> 4;
		m_FrameHeaderInfo.copyright = (m_FrameHeader.byte4 & 8)>>3;
		m_FrameHeaderInfo.original = (m_FrameHeader.byte4 & 4)>>2;
		m_FrameHeaderInfo.emphasis = (m_FrameHeader.byte4 & 3);
		CalculateLenght();
		Trim(m_Tag.album,30);
		Trim(m_Tag.artist,30);
		Trim(m_Tag.comments,28);
		Trim(m_Tag.title,30);
		delete[] tag;
	}
	else
	{
		return(false);
	}
	return(true);
}

bool CMp3FileInfo::SetMP3Info()
{
	CFile f;
	if(f.Open(m_FileName,CFile::modeWrite|CFile::shareExclusive,NULL))
	{
		m_Tag.comments[28]='\0';
		f.Seek(-128,CFile::end);
		f.Write((char*)&m_Tag,sizeof(m_Tag));
		f.Close();
	}
	else
	{
		return(false);
	}
	return(true);
}

bool CMp3FileInfo::NewTag(CString file)
{
	CFile f;
	if(f.Open(file,CFile::modeWrite|CFile::shareExclusive,NULL))
	{
		m_Tag.TAG[0]='T';
		m_Tag.TAG[1]='A';
		m_Tag.TAG[2]='G';
		for(int i=3;i<128;i++)
			m_Tag.TAG[i]='\0';
		f.SeekToEnd();
		f.Write((char*)&m_Tag,sizeof(m_Tag));
		f.Close();
	}
	else
	{
		return(false);
	}
	return(true);
}

char* CMp3FileInfo::GetTitle()
{
	strncpy(tmp,m_Tag.title,30);
	tmp[30]='\0';
	return(tmp);
}

char* CMp3FileInfo::GetArtist()
{
	strncpy(tmp,m_Tag.artist,30);
	tmp[30]='\0';
	return(tmp);
}

char* CMp3FileInfo::GetAlbum()
{
	strncpy(tmp,m_Tag.album,30);
	tmp[30]='\0';
	return(tmp);
}

char* CMp3FileInfo::GetYear()
{
	strncpy(tmp,m_Tag.year,4);
	tmp[4]='\0';
	return(tmp);
}

char CMp3FileInfo::GetGenre()
{
	return(m_Tag.genre);
}

char CMp3FileInfo::GetTrack()
{
	return(m_Tag.track);
}

char* CMp3FileInfo::GetComments()
{
	strncpy(tmp,m_Tag.comments,28);
	tmp[28]='\0';
	return(tmp);
}

void CMp3FileInfo::SetTitle(char *title)
{
	m_Tag.title[0]='\0';
	strncpy(m_Tag.title,title,30);
}

void CMp3FileInfo::SetArtist(char *artist)
{
	m_Tag.artist[0]='\0';
	strncpy(m_Tag.artist,artist,30);
}

void CMp3FileInfo::SetAlbum(char *album)
{
	m_Tag.album[0]='\0';
	strncpy(m_Tag.album,album,30);
}

void CMp3FileInfo::SetYear(char *year)
{
	m_Tag.year[0]='\0';
	strncpy(m_Tag.year,year,4);
}

void CMp3FileInfo::SetGenre(char genre)
{
	m_Tag.genre=genre;
}

void CMp3FileInfo::SetTrack(char track)
{
	m_Tag.track=track;
}

void CMp3FileInfo::SetComments(char *comments)
{
	m_Tag.comments[0]='\0';
	strncpy(m_Tag.comments,comments,28);
	m_Tag.comments[28]='\0';
}

int CMp3FileInfo::GetBitrate()
{
	int mpegVersion=m_FrameHeaderInfo.mpeg_version;
	int mpegLayer=m_FrameHeaderInfo.layer;
	if(mpegVersion==3)
		mpegVersion=0;
	else
		mpegVersion=1;

	if(mpegLayer==3)
		mpegLayer=0;
	else if(mpegLayer==2)
		mpegLayer=1;
	else
		mpegLayer = 2;

	return(bit_rate[mpegVersion][mpegLayer][m_FrameHeaderInfo.bitrate]);
}

int CMp3FileInfo::GetFrequency()
{
	int mpegVersion=m_FrameHeaderInfo.mpeg_version;
	if(mpegVersion==3)
		mpegVersion=0;
	else
		mpegVersion=1;
	return(frequency[mpegVersion][m_FrameHeaderInfo.frequency]);
}

int CMp3FileInfo::GetLength()
{
	return(m_Length);
}

char* CMp3FileInfo::GetCRC()
{
	return(crc[m_FrameHeaderInfo.crc]);
}

char* CMp3FileInfo::GetPadding()
{
	return(yesno[m_FrameHeaderInfo.padding]);
}

char* CMp3FileInfo::GetCopyright()
{
	return(yesno[m_FrameHeaderInfo.copyright]);
}

char* CMp3FileInfo::GetOriginal()
{
	return(yesno[m_FrameHeaderInfo.original]);
}

char* CMp3FileInfo::GetPrivate()
{
	return(yesno[m_FrameHeaderInfo.private_bit]);
}

char* CMp3FileInfo::GetChannelMode()
{
	return(channel_mode[m_FrameHeaderInfo.channel_mode]);
}

char* CMp3FileInfo::GetMpegVersion()
{
	return(mpeg_version[m_FrameHeaderInfo.mpeg_version]);
}

char* CMp3FileInfo::GetMpegLayer()
{
	return(layer[m_FrameHeaderInfo.layer]);
}

char* CMp3FileInfo::GetEmphasis()
{
	return(emphasis[m_FrameHeaderInfo.emphasis]);
}

int CMp3FileInfo::GetFileSize()
{
	return(m_FileSize);
}

int CMp3FileInfo::GetFrames()
{
	return(m_Frames);
}

void CMp3FileInfo::CalculateLenght()
{
	double framelength;
	int mpegVersion=m_FrameHeaderInfo.mpeg_version;
	int mpegLayer=m_FrameHeaderInfo.layer;
	if(mpegVersion==3)
		mpegVersion=0;
	else
		mpegVersion=1;

	if(mpegLayer==3)
		mpegLayer=0;
	else if(mpegLayer==2)
		mpegLayer=1;
	else
		mpegLayer = 2;

	double rate=bit_rate[mpegVersion][mpegLayer][m_FrameHeaderInfo.bitrate]*1000;
	double freq=frequency[mpegVersion][m_FrameHeaderInfo.frequency];
	if(m_FrameHeaderInfo.layer==3)
		framelength=(12*rate/freq+m_FrameHeaderInfo.padding)*4;
	else
		framelength=(144 * rate)/(freq+m_FrameHeaderInfo.padding);

	int dec, sign;
	m_Length = atoi(fcvt((m_FileSize/framelength)*0.0261,0,&dec,&sign));
	m_Frames = atoi(fcvt((m_FileSize/framelength),0,&dec,&sign));
}

void CMp3FileInfo::Trim(char *data, int size)
{
	for(int i=size-1;i>0;i--)
	{
		if(data[i]==' ')
			data[i]='\0';
		else
			break;
	}
}

void CMp3FileInfo::RemoveTag()
{
	CFile f;
	f.Open(m_FileName,CFile::modeWrite|CFile::shareExclusive,NULL);
	f.SetLength(f.GetLength()-128);
	f.Close();
}
