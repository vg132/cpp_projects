#include "MaskPart.h"

MaskPart::MaskPart(int x,int y)
{
	this->x=x;
	this->y=y;
}

void MaskPart::SetX(int x)
{
	this->x=x;
}

void MaskPart::SetY(int y)
{
	this->y=y;
}

int MaskPart::GetX()
{
	return(x);
}

int MaskPart::GetY()
{
	return(y);
}
