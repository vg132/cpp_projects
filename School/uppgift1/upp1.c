#include "upp1.h"

int main(void)
{
	FILE *in;
	struct Line *first_line;
	char infile[FILENAME_MAX];
	int exit=0;
	char c;

	printf("Numed v0.1a\n");
	printf("Fil: ");
	fgets(infile, FILENAME_MAX, stdin);
	*strchr(infile,'\n')='\0';
	in=fopen(infile,"r");
	first_line=read_file(in);

	while(!exit)
	{
		printf("\n\nI: Insert line\n"
		"D: Delete line\n"
		"P: Print line\n"
		"A: Print all lines\n"
		"R: Renumber lines\n"
		"H: Help\n"
		"Q: Quit\n\n");
		printf("Command> ");
		c=getchar();
		while(getchar()!='\n');
		switch(toupper(c))
		{
			case 'I':
				first_line=insert(first_line);
				break;
			case 'D':
				if(first_line!=NULL)
					first_line=deleteline(first_line);
				break;
			case 'P':
				if(first_line!=NULL)
					print(first_line);
				break;
			case 'A':
				if(first_line!=NULL)
					printall(first_line);
				break;
			case 'R':
				if(first_line!=NULL)
					renumber(first_line);
				break;
			case 'H':
				break;
			case 'Q':
				save(first_line);
				exit=1;
				break;
			default:
				fputs("Command not found", stderr);
				break;
		}
	}
	fclose(in);
	return(0);
}

/* lägger till en rad i listan med rader */
struct Line* insert(struct Line *line)
{
	int nr=0, ret=0;
	char buffer[MAX_LINE], *c;
	struct Line *newline, *first=line, *tmp=line;

	printf("Line nr: ");
	ret=scanf("%d",&nr);
	while(getchar()!='\n');
	if(ret!=1)
	{
		fputs("Enter a numeric value.\n",stderr);
		return(first);
	}
	printf("Line: ");
	fgets(buffer,MAX_LINE,stdin);
	c=strchr(buffer,'\n');
	if(c!=NULL)
		*c='\0';

	newline=malloc(sizeof(struct Line));
	newline->line=malloc(strlen(buffer)+1);
	strcpy(newline->line,buffer);
	newline->nr=nr;
	newline->next=NULL;

	return(add_line(line,newline));
}

/* Skriver ut en rad på skärmen */
void show(struct Line *line)
{
	printf("%d: %s\n",line->nr,line->line);
}

/* Skriver ut en vald rad på skärmen */
void print(struct Line *line)
{
	int nr=0, ret=0;
	printf("Line nr: ");
	ret=scanf("%d",&nr);
	while(getchar()!='\n');
	if(ret!=1)
	{
		fputs("Enter a numeric value.\n",stderr);
		return;
	}
	while(line!=NULL)
	{
		if(line->nr==nr)
			break;
		line=line->next;
	}
	if(line==NULL)
		fputs("Line not found.",stderr);
	else
		show(line);
}

/* Skriver ut alla rader på skärmen */
void printall(struct Line *line)
{
	do
	{
		show(line);
	}while((line=line->next));
}

struct Line* deleteline(struct Line *line)
{
	int nr=0, ret=0;

	printf("Delete line nr: ");
	ret=scanf("%d",&nr);
	while(getchar()!='\n');
	if(ret!=1)
	{
		fputs("Enter a numeric value.\n",stderr);
		return(line);
	}
	return(remove_line(line,nr));
}

/* Numrera raderna i structen, börja på 100 och öka med 100 för varje rad */
void renumber(struct Line *line)
{
	int nr=0;
	while(line!=NULL)
	{
		line->nr=nr+=100;
		line=line->next;
	}
}

/* Fråga användaren om den vill spara ändringarna till en fil. */
void save(struct Line *first)
{
	struct Line *cur=NULL;
	char buffer[FILENAME_MAX], *c, save;
	FILE *out;

	printf("Save changes? (Y/N): ");
	scanf("%c",&save);
	while(getchar()!='\n');
	if(toupper(save)=='Y')
	{
		printf("Save to file: ");
		fgets(buffer, FILENAME_MAX, stdin);

		c=strchr(buffer,'\n');
		if(c!=NULL)
			*c='\0';
		out=fopen(buffer,"w");
		write_file(out,first);
		fclose(out);
	}
}

