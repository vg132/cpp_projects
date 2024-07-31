#include <graphics.h>

class Grafik
{
private:
	int    GraphDriver;             // The Graphics device driver           
	int    GraphMode;               // The Graphics mode value              
	double AspectRatio;             // Aspect ratio of a pixel on the screen
	int    MaxX, MaxY;              // The maximum resolution of the screen 
	int    MaxColors;               // The maximum # of colors available    
	int    ErrorCode;               // Reports any graphics errors          
	struct palettetype palette;     // Used to read palette info   
public:
	void Initialize(void);
	void Reset(void);
	void PaintPixle(int x, int y, int color);
	void PrintText(int x, int y, char *text, int color=14, int HorizJust=0, int Font=0, int Size=1);
	void PaintBox(int x, int y, int height, int width,int color);
	void PaintLine(int x1, int y1, int x2, int y2, int color=15);
	int GetMaxX(void);
	int GetMaxY(void);
	int GetColor(int x, int y);
	void ClearScreen();
};