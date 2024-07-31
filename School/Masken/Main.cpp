#include "Mask.cpp"
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void MakeArea();
void SetText();
void Play();
void Init();
void GameOver();
void Score(int score);
void InitGame();
int Intro();

Grafik g;
Mask m;
CDot dot;

int TotalScore=0;

void main()
{
	char ch;
	Init();
	if(Intro()==0)
	{
		MakeArea();
		SetText();
		InitGame();
		Play();
	}
	g.Reset();
}

void Init()
{
	g.Initialize();
	m.SetLimits(2,2,g.GetMaxX()-170,g.GetMaxY()-1);
}

void InitGame()
{
	m.Reset(g,20,2);
	dot.RemoveDot(g);
	TotalScore=0;
	Score(0);
}

void MakeArea()
{
	g.ClearScreen();
	g.PaintLine(0,0,g.GetMaxX(),0);
	g.PaintLine(0,g.GetMaxY(),g.GetMaxX(),g.GetMaxY());
	g.PaintLine(0,0,0,g.GetMaxY());
	g.PaintLine(g.GetMaxX(),0,g.GetMaxX(),g.GetMaxY());
	g.PaintLine(g.GetMaxX()-170,0,g.GetMaxX()-170,g.GetMaxY());
	g.PaintLine(g.GetMaxX()-170,g.GetMaxY()-130,g.GetMaxX(),g.GetMaxY()-130);
	g.PaintLine(g.GetMaxX()-170,g.GetMaxY()-207,g.GetMaxX(),g.GetMaxY()-207);
}

void SetText()
{
	g.PrintText(g.GetMaxX()-160,7,"Score:");

	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-200,"Keys");
	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-187,"Arrows->Move Mask");
	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-174,"R->Restart");
	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-161,"P->Pause");
	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-148,"Q->Quit");

	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-123,"Return of the Mask!");
	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-110,"(C) Viktor Gars and");
	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-97,"Per Fingal 2001");
	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-84,"Published by");
	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-71,"VG Software");
	g.PrintText(g.GetMaxX()-160,g.GetMaxY()-58,"www.vgsoftware.com");
}

void Play()
{
int direction(0);
char ch;
int MaxX=g.GetMaxX()-170;
int MaxY=g.GetMaxY()-1;
int RetVal(0);
int Speed(30);
char tmp;
	delay(50);
	dot.PaintNewDot(g,MaxX,MaxY);
	m.SetDot(dot);
	do
	{
		while (!kbhit())
		{
			m.PaintMask(g);
			delay(Speed);
			RetVal=m.MoveMask(direction,g);
			if(RetVal==1)
			{
				GameOver();
			}
			else if(RetVal==2)
			{
				dot.RemoveDot(g);
				dot.PaintNewDot(g,MaxX,MaxY);
				m.SetDot(dot);
				m.AddMaskPart(15);
				Score((125*m.GetNrMaskParts())/Speed);
				Speed--;
			}
		};
		ch=getch();
		if(ch==72)
			direction=1;
		else if(ch==75)
			direction=3;
		else if(ch==77)
			direction=2;
		else if(ch==80)
			direction=0;
		else if(ch=='p'||ch=='P')
			getch();
		else if(ch=='r'||ch=='R')
		{
			g.ClearScreen();
			InitGame();
			MakeArea();
			direction=2;
			Speed=30;
			dot.PaintNewDot(g,MaxX,MaxY);
			m.SetDot(dot);
			RetVal=0;
		}
	}while(ch!='q'&&RetVal!=1);
}

void GameOver()
{
	g.ClearScreen();
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2-150,"Game Over!",12,1,0,4);
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2-50,"Press \"r\" to Restart!",12,1,0,2);
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2-25,"or",12,1,0,2);
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2,"Perss \"q\" to Quit!",12,1,0,2);
	while (!kbhit())
	{
	};
}

void Score(int score)
{
	char buffer[20];
	TotalScore+=score;
	g.PaintBox(g.GetMaxX()-100,6,90,10,0);
	g.PrintText(g.GetMaxX()-40,7,itoa(TotalScore,buffer,10),14,2);
}

int Intro()
{
	char ch;
	g.ClearScreen();
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2-150,"Return Of The Mask!",12,1,0,4);
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2-50,"Press \"p\" to Play!",12,1,0,2);
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2-25,"or",12,1,0,2);
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2,"Perss \"q\" to Quit!",12,1,0,2);
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2+190,"Copyright (C) Viktor Gars And Per Fingal 2001",12,1,0,1);
	g.PrintText(g.GetMaxX()/2,g.GetMaxY()/2+200,"Published by VG Software http://www.vgsoftware.com/",12,1,0,1);
	do
	{
		ch=getch();
		if(ch=='p'||ch=='P')
			return(0);
		if(ch=='q'||ch=='Q')
			return(1);
	}while(1==1);
}