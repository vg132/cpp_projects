#include <iostream.h>
#include <fstream.h>
#include <io.h>
#include <string.h>

#define BUFFERSIZE	65535

int image_height;
int image_widht;
int image_depth;
enum img_type{unknown, png, gif, bmp, jpg};
img_type image_type;

bool DecodeImage(char* filename);
int Mult(int a, int b);