#include "list.h"

struct Line* read_file(FILE *file)
{
	char buffer[MAX_LINE];
	char *c=NULL;
	struct Line *tmp=NULL,*first=NULL,*last=NULL;
	int linenr=0;
	if(file!=NULL)
	{
		while(fgets(buffer,MAX_LINE,file)!=NULL)
		{
			tmp=malloc(sizeof(struct Line));
			c=strchr(buffer,'\n');
			if(c!=NULL)
				*c='\0';
			tmp->line=malloc(strlen(buffer)+1);
			strcpy(tmp->line,buffer);
			tmp->nr=++linenr;
			tmp->next=NULL;
			if(first==NULL)
				first=tmp;
			else
				last->next=tmp;
			last=tmp;
		}
	}
	return(first);
}

void write_file(FILE *file, struct Line *list)
{
	while((list=list->next))
		fprintf(file,"%s\n",list->line);
}

struct Line* add_line(struct Line *list, struct Line *line)
{
	struct Line *first=list;

	if(first->nr>line->nr)
	{
		line->next=first;
		first=line;
	}
	while((list->next!=NULL)&&(list->next->nr<line->nr))
		list=list->next;

	if(list!=NULL)
	{
		line->next=list->next;
		list->next=line;
	}
	return(first);
}

struct Line* remove_line(struct Line *list, int line_nr)
{
	struct Line *first=list;
	struct Line *tmp=NULL;

	if(list->nr==line_nr)
	{
		first=list->next;
		free(list->line);
		free(list);
	}
	else
	{
		while((list->next!=NULL)&&(list->next->nr!=line_nr))
			list=list->next;
		if((list->next!=NULL)&&(list->next->nr==line_nr))
		{
			tmp=list->next;
			list->next=tmp->next;
			free(tmp->line);
			free(tmp);
		}
		else
		{
			fprintf(stderr,"Line nr %d not found.",line_nr);
		}
	}
	return(first);
}

int free_list(struct Line *list)
{
	if(list->next!=NULL)
		free_list(list->next);
	free(list->line);
	free(list);
	return(0);
}
