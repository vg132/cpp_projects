#ifndef __UPP1__H__
#define __UPP1__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define MAX_LINE 1000

void save(struct Line *first);
struct Line* deleteline(struct Line *line);
void renumber(struct Line *line);
void print(struct Line *line);
void printall(struct Line *line);
void show(struct Line *line);
struct Line* insert(struct Line *line);

#endif
