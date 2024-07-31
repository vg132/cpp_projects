#include "Mask.cpp"
#include <dos.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

void Init();
void Paint1();
void Paint2();
void Paint3();
void MoveMaskToFirst();
Grafik g;

void main()
{
	g.Initialize();
	Init();
	while(!kbhit())
	{
	};
	getch();
	g.Reset();
}

void Init()
{
	Paint1();
	Paint2();
	Paint3();
	MoveMaskToFirst();
}

void Paint1()
{
	g.PaintLine(0,20,30,50);
	g.PaintLine(0,80,30,50);
}

void Paint2()
{
	g.PaintLine(g.GetMaxX(),g.GetMaxY()/2-30,g.GetMaxX()-30,g.GetMaxY()/2);
	g.PaintLine(g.GetMaxX(),g.GetMaxY()/2+30,g.GetMaxX()-30,g.GetMaxY()/2);
}

void Paint3()
{
	g.PaintLine(0,g.GetMaxY()-90,30,g.GetMaxY()-60);
	g.PaintLine(0,g.GetMaxY()-30,30,g.GetMaxY()-60);
}

void MoveMaskToFirst()
{
	//Create mask

	Mask m;
	int i;
	m.Reset(g,20,4,g.GetMaxX()/2,g.GetMaxY()/2);

	// Paint mask at start point (center of screen)

	for(i=0;i<20;i++)
		m.MoveMask(3,g);
	m.PaintMask(g);

	//Animate "?" marks

	g.PrintText((g.GetMaxX()/2)-80,(g.GetMaxY()/2)-10,"?",14,1,0,1);
//	delay(3000);
	g.PrintText((g.GetMaxX()/2)-70,(g.GetMaxY()/2)-10,"?",14,1,0,1);
//	delay(2000);
	g.PrintText((g.GetMaxX()/2)-60,(g.GetMaxY()/2)-10,"?",14,1,0,1);
//	delay(2500);
	g.PaintBox((g.GetMaxX()/2)-84,(g.GetMaxY()/2)-10,30,8,0);
//	delay(1000);
	g.PrintText((g.GetMaxX()/2)-70,(g.GetMaxY()/2)-30,"!",14,1,0,3);
//	delay(1000);
	g.PrintText((g.GetMaxX()/2)-70,(g.GetMaxY()/2)-30,"!",0,1,0,3);

	//Move mask to firt corner

	for(i=0;i<52;i++)
	{
		m.MoveMask(3,g);
		m.PaintMask(g);
//		delay(30);
	}

	//Move mask to first item

	for(i=0;i<48;i++)
	{
		m.MoveMask(1,g);
		m.PaintMask(g);
		delay(30);
	}

	//Move mask to other side of screen

	for(i=0;i<143;i++)
	{
		m.MoveMask(2,g);
		m.PaintMask(g);
		if(i>20)
		{	
			g.PaintLine(0+((i-17)*4),20,30+((i-17)*4),50);
			g.PaintLine(0+((i-17)*4),80,30+((i-17)*4),50);
			g.PrintText(0+((i-17)*4),80,"Hej viktor");
		}
		delay(30);
		g.ClearScreen();
	}
/*
	//Move mask to next item
	for(i=0;i<48;i++)
	{
		m.MoveMask(0,g);
		m.PaintMask(g);
		delay(30);
	}

	//Move mask to other side of screen
	for(i=0;i<143;i++)
	{
		m.MoveMask(3,g);
		m.PaintMask(g);
		delay(30);
	}

	//Move mask to next item
	for(i=0;i<45;i++)
	{
		m.MoveMask(0,g);
		m.PaintMask(g);
		delay(30);
	}

	//Move mask to other side of screen

	for(i=0;i<143;i++)
	{
		m.MoveMask(2,g);
		m.PaintMask(g);
		delay(30);
	}*/
}
