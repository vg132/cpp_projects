// Track.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Track.h"

#include "LoadText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrack

IMPLEMENT_DYNCREATE(CTrack, CFormView)

CTrack::CTrack()
	: CFormView(CTrack::IDD)
{
	//{{AFX_DATA_INIT(CTrack)
	m_Laps = 0;
	m_Year = 0;
	m_Length = 0;
	m_Record = _T("");
	//}}AFX_DATA_INIT
}

CTrack::~CTrack()
{
}

void CTrack::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrack)
	DDX_Control(pDX, IDC_TRACK_SPIN_YEAR, m_Spin_Year);
	DDX_Control(pDX, IDC_TRACK_SPIN_LENGTH, m_Spin_Length);
	DDX_Control(pDX, IDC_TRACK_SPIN_LAPS, m_Spin_Laps);
	DDX_Control(pDX, IDC_TRACK_COMBO_TEAM, m_Team);
	DDX_Control(pDX, IDC_TRACK_COMBO_DRIVER, m_Driver);
	DDX_Text(pDX, IDC_TRACK_EDIT_LAPS, m_Laps);
	DDV_MinMaxInt(pDX, m_Laps, 0, 255);
	DDX_Text(pDX, IDC_TRACK_EDIT_YEAR, m_Year);
	DDV_MinMaxInt(pDX, m_Year, 0, 32000);
	DDX_Text(pDX, IDC_TRACK_EDIT_LENGTH, m_Length);
	DDV_MinMaxInt(pDX, m_Length, 0, 9999);
	DDX_Text(pDX, IDC_TRACK_EDIT_RECORD, m_Record);
	DDV_MaxChars(pDX, m_Record, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTrack, CFormView)
	//{{AFX_MSG_MAP(CTrack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrack diagnostics

#ifdef _DEBUG
void CTrack::AssertValid() const
{
	CFormView::AssertValid();
}

void CTrack::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTrack message handlers

void CTrack::Load(int id, CString file)
{
CFile f;
int iData;
char Len[5];
int min=0;
int sec=0;

	m_Id=id;

	f.Open(file,CFile::modeRead,NULL);
	
	f.Seek(2772962+(132*id),CFile::begin);
	f.Read((char*)&Len,sizeof(Len));
	double tmp=atof(Len);
	tmp*=1000;
	m_Length=(int)tmp;
	f.Seek(21,CFile::current);
	f.Read((char*)&m_Laps,sizeof(int));
	f.Seek(4,CFile::current);
	f.Read((char*)&iData,sizeof(int));
	
	int iItemData;
	if(iData<200)
		iData-=1;
	for(int i=0;i<48;i++)
	{
		iItemData=m_Driver.GetItemData(i);
		if(iItemData==iData)
			m_Driver.SetCurSel(i);
	}
	f.Read((char*)&iData,sizeof(int));
	m_Team.SetCurSel(iData-1);
	f.Read((char*)&iData,sizeof(int));

	for(;iData>60000;iData-=60000)
		min++;
	for(;iData>1000;iData-=1000)
		sec++;
	CString t;
	char buffer[20];
	itoa(min,buffer,10);
	t=buffer;
	t+=":";
	itoa(sec,buffer,10);
	t+=buffer;
	t+=".";
	itoa(iData,buffer,10);
	t+=buffer;
	m_Record=t;

	f.Seek(4,CFile::current);
	f.Read((char*)&m_Year,sizeof(int));

	f.Close();
	UpdateData(FALSE);
}

void CTrack::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	FillBox();
	SetSpin();
}

void CTrack::FillBox()
{
CLoadText m_Text;
int i;
int tmp;
int iDriv[41]={5,6,7,13,14,15,21,22,29,30,31,37,
			   38,45,46,47,53,54,55,61,62,63,69,
			   70,77,78,79,85,86,87,128,129,130,
			   131,132,133,134,135,136,137,138};

	m_Text.LoadText();
	m_Driver.AddString("None");
	m_Driver.SetItemData(0,0);
	for(i=0;i<41;i++)
	{
		tmp=m_Driver.AddString(m_Text.m_Name[iDriv[i]]);
		m_Driver.SetItemData(tmp,iDriv[i]);
	}
	for(i=0;i<4;i++)
	{
		tmp=m_Driver.AddString(m_Text.m_RecNames[i]);
		m_Driver.SetItemData(tmp,200+i);
	}
	for(i=1;i<12;i++)
		m_Team.AddString(m_Text.m_Teams[i]);
}

void CTrack::SetSpin()
{
	m_Spin_Laps.SetRange(0,255);
	m_Spin_Length.SetRange(0,9999);
	m_Spin_Year.SetRange(0,32000);
}

void CTrack::Save(CString file)
{
CFile f;
char* s;
double len;
int iData;

	UpdateData(TRUE);
	f.Open(file,CFile::modeWrite,NULL);
	f.Seek(2772956+(132*m_Id),CFile::begin);

	//Track Length/lap (miles)
	len=m_Length;
	len*=0.6213688;
	len/=1000;
	s=ConvertLapString(len);
	f.Write(s,5);
	//(meters)
	f.Seek(1,CFile::current);
	len=m_Length;
	len/=1000;
	s=ConvertLapString(len);
	f.Write(s,5);
	//Track Length/race (miles)
	f.Seek(1,CFile::current);
	len=m_Length;
	len*=m_Laps;
	len*=0.6213688;
	len/=1000;
	s=ConvertRaceString(len);
	f.Write(s,7);
	//meters
	f.Seek(3,CFile::current);
	len=m_Length;
	len*=m_Laps;
	len/=1000;
	s=ConvertRaceString(len);
	f.Write(s,7);
	//laps
	f.Seek(3,CFile::current);
	f.Write((char*)&m_Laps,sizeof(int));
	//Driver
	f.Seek(4,CFile::current);
	iData=m_Driver.GetItemData(m_Driver.GetCurSel())+1;
	f.Write((char*)&iData,sizeof(int));
	//Team
	iData=m_Team.GetCurSel()+1;
	f.Write((char*)&iData,sizeof(int));
	//Time

	CString c;
	CString cb;
	char ch;
	c=m_Record;
	int i=0;
	int min=0;
	int sec=0;
	int mili=0;
	int time=0;


	while((ch=c.GetAt(i))&&(ch>47&&ch<58))
	{
		cb+=ch;
		i++;
	}

	min=atoi(cb)*60000;
	c.Delete(0,i+1);
	i=0;
	cb="";

	while((ch=c.GetAt(i))&&(ch>47&&ch<58))
	{
		cb+=ch;
		i++;
	}

	sec=atoi(cb)*1000;

	c.Delete(0,i+1);
	mili=atoi(c);
	time=min+sec+mili;
	f.Write((char*)&time,sizeof(int));

	//Year
	f.Seek(4,CFile::current);
	f.Write((char*)&m_Year,sizeof(int));
	//Close File!
	f.Close();
}

char* CTrack::ConvertLapString(double len)
{
char* string = new char;
char* c;
int decimal, sign;

	c=ecvt(len,4,&decimal,&sign);
	
	if(decimal==1)
	{
		strncpy(string,c,1);
		strncpy(string+1,".",1);
		strncpy(string+2,c+1,3);
	}
	else if(decimal==0)
	{
		strncpy(string,"0.",2);
		strncpy(string+2,c,3);
	}
	else if(decimal==-1)
	{
		strncpy(string,"0.0",3);
		strncpy(string+3,c,2);
	}
	else if(decimal==-2)
	{
		strncpy(string,"0.00",4);
		strncpy(string+4,c,1);
	}
	return(string);
}

char* CTrack::ConvertRaceString(double len)
{
char* string=new char;
char* c;
int decimal, sign;

	c=ecvt(len,6,&decimal,&sign);
	if(decimal==3)
	{
		strncpy(string,c,3);
		strncpy(string+3,".",1);
		strncpy(string+4,c+3,3);
	}
	else if(decimal==2)
	{
		strncpy(string,"0",1);
		strncpy(string+1,c,2);
		strncpy(string+3,".",1);
		strncpy(string+4,c+2,4);
	}
	else if(decimal==1)
	{
		strncpy(string,"00",2);
		strncpy(string+2,c,1);
		strncpy(string+3,".",1);
		strncpy(string+4,c+1,3);
	}
	else if(decimal==0)
	{
		strncpy(string,"000.",4);
		strncpy(string+4,c,3);
	}
	else if(decimal==-1)
	{
		strncpy(string,"000.0",5);
		strncpy(string+5,c,2);
	}
	else if(decimal==-2)
	{
		strncpy(string,"000.00",6);
		strncpy(string+6,c,1);
	}
	return(string);
}

