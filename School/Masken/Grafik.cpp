#include "Grafik.h"

void Grafik::Initialize(void)
{
  int xasp, yasp;                       // Used to read the aspect ratio
	GraphMode=1;
  GraphDriver = DETECT;                 // Request auto-detection
  initgraph( &GraphDriver, &GraphMode, "" );
  ErrorCode = graphresult();            // Read result of initialization

  getpalette( &palette );               // Read the palette from board
  MaxColors = getmaxcolor() + 1;        // Read maximum number of colors

  MaxX = getmaxx();
  MaxY = getmaxy();                     // Read size of screen

  getaspectratio( &xasp, &yasp );       // read the hardware aspect
  AspectRatio = (double)xasp / (double)yasp; // Get correction factor
}

void Grafik::Reset(void)
{
	closegraph();		// Change to text mode
}

void Grafik::PaintPixle(int x, int y, int color)
{
	putpixel(x, y, color);
}

void Grafik::PrintText(int x,int y, char *text,int color, int HorizJust, int Font, int Size)
{
  setcolor(color);
	settextstyle(Font, HORIZ_DIR,Size);
	settextjustify(HorizJust, TOP_TEXT);
	outtextxy(x, y,text);
}

void Grafik::PaintBox(int x, int y, int height, int width, int color)
{
	setfillstyle(SOLID_FILL, color);
	bar(x,y,x+height,y+width);
}

int Grafik::GetMaxX()
{
	return(MaxX);
}

int Grafik::GetMaxY()
{
	return(MaxY);
}

void Grafik::PaintLine(int x1, int y1, int x2, int y2, int color)
{
//	setlinestyle(style, 0, THICK_WIDTH);
	setcolor(color);
	line(x1, y1, x2, y2);
}

int Grafik::GetColor(int x, int y)
{
	return(getpixel(x,y));
}

void Grafik::ClearScreen()
{
	cleardevice();
}