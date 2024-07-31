#include "cset.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <stdio.h>

int main()
{
	Set s1,s2,s3,s4;
	s1=setmake(5,0,1,10,36,188);
	s2=setmake(2,10,38);
	if(issubset(s2,s1))
		printf("YES!\n");
	else
		printf("NO!\n");
	/*
	printf("Set 1: ");
	setprint(s1);
	printf(" - %d\n", setcardinal(s1));
	printf("Set 2: ");
	setprint(s2);
	printf(" - %d\n", setcardinal(s2));
	printf("Set 3: ");
	setprint(s3);
	printf(" - %d\n", setcardinal(s3));
	*/
	return(0);
}
