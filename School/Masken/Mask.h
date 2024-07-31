#include "MaskPart.cpp"
#include "Grafik.cpp"
#include "Dot.cpp"

class Mask
{
private:
	int NrMaskParts;
	int size;
	MaskPart *MaskParts;
	int top, left, right, bottom;
	CDot dot;
public:
	Mask();
	~Mask();
	void AddMaskPart(int Parts=4);
	int GetNrMaskParts();
	int MoveMask(int,Grafik g);
	void PaintMask(Grafik);
	void SetLimits(int top, int left, int right, int bottom);
	void SetDot(CDot dot);
	void Reset(Grafik g, int lenght,int size,int startX=50, int startY=50);
};