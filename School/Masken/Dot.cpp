#include "Dot.h"

CDot::CDot(int size)
{
	this->size=size;
	srand(unsigned(time(NULL)));
	x=0;
	y=0;
}

void CDot::PaintNewDot(Grafik g,int MaxX,int MaxY)
{
char *ch;
	x=(rand()%MaxX+1);
	y=(rand()%MaxY+1);
	g.PaintBox(x,y,size,size,14);
}

int CDot::GetX()
{
	return(x);
}

int CDot::GetY()
{
	return(y);
}

int CDot::GetSize()
{
	return(size);
}

void CDot::SetSize(int size)
{
	this->size=size;
}

void CDot::RemoveDot(Grafik g)
{
	if(x!=0&&y!=0)
		g.PaintBox(x,y,size,size,0);
}