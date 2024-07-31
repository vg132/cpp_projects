#ifndef __CSTRUCTS__
#define __CSTRUCTS__

struct Drive
{
	char DriveName[21];
	char DriveLetter[2];
	char DriveTitle[27];
	int DriveType;
};

struct PathInfo
{
	char Path[260];
};

struct FileInfo
{
	char FileName[260];
	bool File;
	FILETIME Changed;
	int Size;
};

#endif