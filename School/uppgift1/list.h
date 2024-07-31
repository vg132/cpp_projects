#ifndef __LIST__H__
#define __LIST__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

typedef struct Line
{
	char *line;
	int nr;
	struct Line *next;
};

struct Line* read_file(FILE *file);
void write_file(FILE *file, struct Line *list);
struct Line* add_line(struct Line *list, struct Line *line);
struct Line* remove_line(struct Line *list, int line_nr);
int free_list(struct Line *list);

#endif
