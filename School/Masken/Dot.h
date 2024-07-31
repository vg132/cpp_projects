#include <time.h>
#include <stdlib.h>

class CDot  
{
private:
	int x;
	int y;
	int size;
public:
	void SetSize(int size);
	int GetY();
	int GetX();
	int GetSize();
	void PaintNewDot(Grafik g,int MaxX, int MaxY);
	void RemoveDot(Grafik g);
	CDot(int size=2);
};