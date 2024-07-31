#ifndef __MP3FILEINFO__
#define __MP3FILEINFO__

struct Mp3FrameHeader
{
 char byte1;
 char byte2;
 char byte3;
 char byte4;
};

struct Mp3FrameHeaderInfo
{
	int mpeg_version;
	int layer;
	int crc;
	int bitrate;
	int frequency;
	int padding;
	int private_bit;
	int channel_mode;
	int mode_extension;
	int copyright;
	int original;
	int emphasis;
};

// Tag Version 1.1
struct Mp3Tag11
{
	char TAG[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comments[29];
	char track;
	char genre;
};
// Tag version 1.0
struct Mp3Tag10
{
	char TAG[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comments[30];
	char genre;
};

class CMp3FileInfo
{
private:
	void Trim(char *data, int size);
	void CalculateLenght();

	Mp3Tag11 m_Tag;
	Mp3FrameHeader m_FrameHeader;
	Mp3FrameHeaderInfo m_FrameHeaderInfo;
	int m_Length;
	int m_Frames;
	int m_FileSize;
	CString m_FileName;
	char tmp[31];
	char *dummy;

public:
	void RemoveTag();
	CMp3FileInfo();
	~CMp3FileInfo();
	bool GetMP3Info(CString file);
	bool SetMP3Info();
	bool NewTag(CString file);
	char* GetTitle();
	char* GetArtist();
	char* GetAlbum();
	char* GetYear();
	char GetGenre();
	char* GetComments();
	char GetTrack();

	void SetTitle(char *title);
	void SetArtist(char *artist);
	void SetAlbum(char *album);
	void SetYear(char *year);
	void SetGenre(char genre);
	void SetComments(char *comments);
	void SetTrack(char track);

	char* GetCRC();
	char* GetPadding();
	char* GetCopyright();
	char* GetOriginal();
	char* GetPrivate();
	char* GetChannelMode();
	char* GetMpegVersion();
	char* GetMpegLayer();
	char* GetEmphasis();

	int GetBitrate();
	int GetFrequency();
	int GetLength();
	int GetFrames();
	int GetFileSize();
};

#endif