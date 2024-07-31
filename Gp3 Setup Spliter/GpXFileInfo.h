#ifndef __CGPXFILEINFO__H__
#define __CGPXFILEINFO__H__

class CGpXFileInfo  
{
private:
	int m_FileType;
public:
	void SetFileType(int FileType);
	int GetFileType();
	CGpXFileInfo();
	~CGpXFileInfo();
};

#endif
