#include "Score.h"

CScore::CScore()
{
	score=0;
}
/*
void CScore::Score(Grafik g, char *score)
{
	char buffer[20];
	this->score+=atoi(score);
	itoa(this->score,buffer,10);
	g.PrintText(g.GetMaxX()-40,7,buffer);
}*/

void CScore::Score(Grafik g, int score2)
{
	char buffer[20];
	this->score+=score2;
	g.PrintText(g.GetMaxX()-40,7,itoa(this->score,buffer,10));
}