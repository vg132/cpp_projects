#include "cset.h"

#define MAIN_INDEX(X) X/8
#define SUB_INDEX(X) (X-(MAIN_INDEX(X)*8))
#define ASSERT(MIN,MAX) assert((e>=MIN)&&(e<=MAX))
#define RESET(DATA,SIZE) memset(DATA,0,SIZE)

Set setmake(int argc, ...)
{
	Set s;
	va_list ap;
	memset(s.data,0,sizeof(char)*64);
	va_start(ap,argc);
	while(argc--)
		setadd(&s,va_arg(ap,int));
	va_end(ap);
	return(s);
}

void setadd(Set *s, int e)
{
	ASSERT(0,511);
	s->data[MAIN_INDEX(e)]|=0x01UL<<SUB_INDEX(e);
}

void setsub(Set *s, int e)
{
	ASSERT(0,511);
	if(ismember(*s,e))
		s->data[MAIN_INDEX(e)]&=~(0x01UL<<SUB_INDEX(e));
}

int ismember(Set s, int e)
{
	if((e>=0)&&(e<512))
		return(s.data[MAIN_INDEX(e)] & 1UL<<SUB_INDEX(e));
	return(0);
}

Set setintersection(Set s1, Set s2)
{
	Set sTmp;
	int i;
	memset(sTmp.data,0,sizeof(char)*64);
	for(i=0;i<64;i++)
		sTmp.data[i]=s1.data[i] & s2.data[i];
	return(sTmp);
}

void setprint(Set s)
{
	int i;
	for(i=0;i<512;i++)
	{
		if(ismember(s,i))
			printf("%d, ",i);
	}
}

int setcardinal(Set s)
{
	int i, nr=0;
	for(i=0;i<512;i++)
	{
		if(ismember(s,i))
			nr++;
	}
	return(nr);
}

int isequalset(Set s1, Set s2)
{
	int i;
	for(i=0;i<64;i++)
	{
		if(s1.data[i]!=s2.data[i])
			return(0);
	}
	return(1);
}

int issubset(Set s1, Set s2)
{
	int i;
	for(i=0;i<512;i++)
	{
		if((ismember(s1,i))&&(!ismember(s2,i)))
			return(0);
	}
	return(1);
}

Set setunion(Set s1, Set s2)
{
	Set sTmp;
	int i;
	for(i=0;i<64;i++)
		sTmp.data[i]=s1.data[i]^s2.data[i];
	return(sTmp);
}
