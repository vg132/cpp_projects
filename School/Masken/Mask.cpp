#include "Mask.h"

Mask::Mask()
{
	NrMaskParts=0;
}

Mask::~Mask()
{
	delete[] MaskParts;
}

void Mask::Reset(Grafik g,int length,int size, int startX, int startY)
{
	int i(0);
	if(NrMaskParts!=0)
	{
		for(int i=0;i<NrMaskParts;i++)
			g.PaintBox(MaskParts[i].GetX(),MaskParts[i].GetY(),size,size,0);
		delete[] MaskParts;
	}
	MaskParts = new MaskPart[length];
	NrMaskParts=length;
	for(i=0;i<NrMaskParts;i++)
	{
		MaskParts[i].SetX(startX);
		MaskParts[i].SetY(startY);
	}
	this->size=size;
}

void Mask::AddMaskPart(int Parts)
{
MaskPart *tmpMask = new MaskPart[NrMaskParts+Parts];
int i(0);

	for(i=0;i<NrMaskParts;i++)
		tmpMask[i]=MaskParts[i];
	delete[] MaskParts;
	MaskParts = new MaskPart[NrMaskParts+Parts];
	for(i=0;i<NrMaskParts;i++)
		MaskParts[i]=tmpMask[i];
	for(i=NrMaskParts;i<NrMaskParts+Parts;i++)
		MaskParts[i]=MaskParts[NrMaskParts-1];
	NrMaskParts+=Parts;
	delete[] tmpMask;
}

int Mask::GetNrMaskParts()
{
	return(NrMaskParts);
}

int Mask::MoveMask(int Direction, Grafik g)
{
MaskPart *tmpMask = new MaskPart[NrMaskParts-1];
int i(0);

	for(i=0;i<NrMaskParts-1;i++)
		tmpMask[i]=MaskParts[i];
	if(Direction==0) //Down!
		MaskParts[0].SetY(MaskParts[0].GetY()+(1*size));
	else if(Direction==1) //Up!
		MaskParts[0].SetY(MaskParts[0].GetY()-(1*size));
	else if(Direction==2) //Right!
		MaskParts[0].SetX(MaskParts[0].GetX()+(1*size));
	else if(Direction==3) //Left!
		MaskParts[0].SetX(MaskParts[0].GetX()-(1*size));
	for(i=0;i<NrMaskParts-1;i++)
		MaskParts[i+1]=tmpMask[i];
	delete[] tmpMask;

	int MaskX = MaskParts[0].GetX();
	int MaskY = MaskParts[0].GetY();
	
	//Check if mask is hitting any objects.
	//If it hits anything else then a yellow (14) object it returns 1.
	//Yellow objects are the once that the mask will eat!
	//If hi hits a border or himself he returns 1, if no hit then reutrn 0

	if(Direction==0)
	{
		if((g.GetColor(MaskX,MaskY+size)!=0)||(g.GetColor(MaskX+size,MaskY+size)!=0))
		{
			if((g.GetColor(MaskX,MaskY+size)==14)||(g.GetColor(MaskX+size,MaskY+size)==14))
				return(2);
			else
				return(1);
		}
		else if(MaskY+size>=bottom)
		{
			return(1);
		}
	}
	else if(Direction==1)
	{
		if((g.GetColor(MaskX,MaskY)!=0)||(g.GetColor(MaskX+size,MaskY)!=0))
		{
			if((g.GetColor(MaskX,MaskY)==14)||(g.GetColor(MaskX+size,MaskY)==14))
				return(2);
			else
				return(1);
		}
		else if(MaskY<=top)
		{
			return(1);
		}
	}
	else if(Direction==2)
	{
		if((g.GetColor(MaskX+size,MaskY)!=0)||(g.GetColor(MaskX+size,MaskY+size)!=0))
		{
			if((g.GetColor(MaskX+size,MaskY)==14)||(g.GetColor(MaskX+size,MaskY+size)==14))
				return(2);
			else
				return(1);
		}
		else if(MaskX+size>=right)
		{
			return(1);
		}
	}
	else if(Direction==3)
	{
		if((g.GetColor(MaskX,MaskY)!=0)||(g.GetColor(MaskX,MaskY+size)!=0))
		{
			if((g.GetColor(MaskX,MaskY)==14)||(g.GetColor(MaskX,MaskY+size)==14))
				return(2);
			else
				return(1);
		}
		else if(MaskX<=left)
		{
			return(1);
		}
	}
	return(0);
}

void Mask::PaintMask(Grafik g)
{
	for(int i=0;i<NrMaskParts-1;i++)
		g.PaintBox(MaskParts[i].GetX(),MaskParts[i].GetY(),size,size,12);
	g.PaintBox(MaskParts[i].GetX(),MaskParts[i].GetY(),size,size,0);
}

void Mask::SetLimits(int top,int left,int right,int bottom)
{
	this->top=top;
	this->left=left;
	this->right=right;
	this->bottom=bottom;
}

void Mask::SetDot(CDot dot)
{
	this->dot=dot;
}
