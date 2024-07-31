#ifndef __SYSTEMIMAGELIST__H__
#define __SYSTEMIMAGELIST__H__

class CSystemImageList
{
public:
	CSystemImageList();
	~CSystemImageList();

protected:
	CImageList m_SmallImageList;
	CImageList m_LargeImageList;
};

#endif
