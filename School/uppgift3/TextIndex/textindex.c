#include "textindex.h"

/* L�ser in alla parametrar och �ppnar/st�nger filerna som beh�vs */
/* av programet */
int main(int argc, char **argv)
{
	FILE *inFile;
	FILE *outFile;
	int i=0;
	tree=InitTree(&compare);

	pageSize=60;
	addToOutput=0;
	newPage=0;
	outFile=stdout;

	for(i=1;i<argc;i++)
	{
		if(argv[i][0]=='-')
		{
			switch(argv[i][1])
			{
				case 'a':
					addToOutput=1;
					break;
				case 'b':
					newPage=1;
					break;
				case 'p':
					pageSize=atoi(&argv[i][2]);
					break;
				case 'o':
					outFile=fopen(&argv[i][2],"w");
					break;
			}
		}
		else
		{
			inFile=fopen(argv[i],"r");
			FindWords(inFile,outFile);
			fclose(inFile);
		}
	}
	fputc('\f',outFile);
	DoForAll(tree,print,outFile);
	fclose(outFile);
	DeleteAll(tree,Delete,NULL);
	free(tree);
	return(0);
}

/* S�ker efter ord i en fil och agerar beroende p� parametrarna som */
/* anv�ndaren gav till programmet. */
void FindWords(FILE *inFile, FILE *outFile)
{
	static int rowcound=0, page=0;
	int ch;
	char word[100];
	int inWord=0;
	word[0]='\0';

	if((newPage)||(page==0))
		page++;

	while((ch=fgetc(inFile))!=EOF)
	{
		if(addToOutput)
			fputc(ch,outFile);
		if((ch=='\f')||(ch==' ')||(ch=='\n')||(ch=='\t')||(ch=='\r'))
		{
			if(inWord)
			{
				NewWord(word,page);
				inWord=0;
				word[0]='\0';
			}
			if(ch=='\f')
			{
				page++;
				rowcound=0;
			}
			if(ch=='\n')
			{
				rowcound++;
				if(!(rowcound%pageSize))
					page++;
			}
		}
		else
		{
			inWord=1;
			strcat(word,(char*)&ch);
		}
	}
}

/* Anv�nds f�r att ta bort element fr�n det bin�ra tr�det. */
void Delete(void * param1, void *extra)
{
	WordItem *wi=(WordItem*)param1;
	free(wi->pages);
	free(wi->word);
	free(wi);
}

/* Skriver ut index sidan och anroppas av doforall i bin�ra tr�det */
void print(void *param1, void *extra)
{
	int i;
	WordItem *wi=(WordItem*)param1;
	fprintf((FILE*)extra,"%s: ",wi->word);

	for(i=0;i<(wi->page+1);i++)
		fprintf((FILE*)extra,"%d, ",wi->pages[i]);
	fprintf((FILE*)extra,"\n");
}

/* G�mf�relse funktion som anv�nds av det bin�ra tr�det */
int compare(void *param1, void *param2, void *extra)
{
	if(!extra)
	{
		return(strcmp(((WordItem*)param2)->word,((WordItem*)param1)->word));
	}
	else if(!strcmp((char*)extra,"find"))
	{
		return(strcmp((char*)param2,((WordItem*)param1)->word));
	}
}

/* L�gger till ordet i tr�det om det inte finns redan */
/* om ordet redan finns s� kollar den om senaste sidan �r sammma */
/* som denna, om det �r det s� g�rs inget, annars s� l�ggs nuvarande */
/* sida till i arrayen, arrayen ut�kas ocks� om det beh�vs */
void NewWord(const char *word, int page)
{
	WordItem *wi;
	char *tmp;
	wi=FindItem(tree,(void*)word,"find");
	if(wi==NULL)
	{
		wi=malloc(sizeof(WordItem));
		wi->page=0;
		wi->pages=calloc(CHUNK,sizeof(int));
		wi->pages[wi->page]=page;
		wi->nrOfPages=CHUNK;
		tmp=malloc(strlen(word)+1);
		strcpy(tmp,word);
		wi->word=tmp;
		AddItem(tree,wi,NULL);
	}
	else if(wi->pages[wi->page]!=page)
	{
		wi->pages[++wi->page]=page;
		if(wi->nrOfPages<=wi->page)
			wi->pages=realloc(wi->pages,(wi->nrOfPages+CHUNK)*sizeof(int));
	}
}
