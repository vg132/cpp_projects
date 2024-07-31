#ifndef __8F41D54BC9785F22A533__TEXTINDEX__H__
#define __8F41D54BC9785F22A533__TEXTINDEX__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"

#define CHUNK 20

typedef struct worditem
{
	char *word;
	int *pages;
	int page;
	int nrOfPages;
}WordItem;

BinTree *tree;
int pageSize, addToOutput, newPage;

void FindWords(FILE *inFile, FILE *outFile);
void print(void *param1, void *extra);
int compare(void *param1, void *param2, void *extra);
void NewWord(const char *word, int page);
void Delete(void * param1, void *extra);

#endif // __8F41D54BC9785F22A533__TEXTINDEX__H__
