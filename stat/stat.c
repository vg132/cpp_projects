#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	FILE *fp=NULL;

	unsigned long int uploaded;
	unsigned long int downloaded;
	unsigned long int uploadResets;
	unsigned long int downloadResets;
	unsigned long int online;
	unsigned long int offline;

	unsigned long int newUpload;
	unsigned long int newDownload;
	unsigned long int newOnline;
	unsigned long int newOffline;

	if(argc==6)
	{
		if((fp=fopen(argv[1],"r"))!=NULL)
		{
			fscanf(fp,"%lu%lu%lu%lu%lu%lu",&uploadResets,&uploaded,&downloadResets,&downloaded,&online,&offline);
			fclose(fp);

			newDownload=strtoul(argv[2],NULL,10);
			newUpload=strtoul(argv[3],NULL,10);
			newOnline=strtoul(argv[4],NULL,10);
			newOffline=strtoul(argv[5],NULL,10);

			if(newDownload<downloaded)
				downloadResets++;
			downloaded=newDownload;
			if(newUpload<uploaded)
				uploadResets++;
			uploaded=newUpload;

			online+=newOnline;
			offline+=newOffline;

			fp=fopen(argv[1],"w");
			fprintf(fp,"%lu %lu %lu %lu %lu %lu",uploadResets,uploaded,downloadResets,downloaded,online,offline);
			fclose(fp);
		}
	}
	else
	{
		printf("Usage: stat [DATABASE] [DOWNLOAD] [UPLOAD] [ONLINE] [OFFLINE]\n");
	}
	return(0);
}
