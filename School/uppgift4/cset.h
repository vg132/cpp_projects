#ifndef __854DB480EA3935E34A6272__CSET__H__
#define __854DB480EA3935E34A6272__CSET__H__

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

#define EXTENDED

typedef struct set
{
	char data[64];
}Set;

void setadd(Set *s, int e);
void setsub(Set *s, int e);
Set setmake(int argc, ...);
int ismember(Set s, int e);
void setprint(Set s);
Set setintersection(Set s1, Set s2);
Set setunion(Set s1, Set s2);
int issubset(Set s1, Set s2);
int isequalset(Set s1, Set s2);
int setcardinal(Set s);

#endif // __854DB480EA3935E34A6272__CSET__H__
