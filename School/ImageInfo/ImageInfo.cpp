#include "ImageInfo.h"

void main()
{
	long hFile;
	ofstream of;
	of.open("c:\\test.txt",ios::out);

	struct _finddata_t c_file;
	if((hFile==_findfirst("E:\\My Intranet\\viktor_dns2go_test\\dbs.galeforcef1.com\\photo\\*.*",&c_file))==-1L)
	{
		cout << "No '*.jpg' files in the directory" << endl;
	}
	else
	{
		if(DecodeImage(c_file.name))
		{
			of.write((char*)"Hej\0",5);
		}
		/* Find the rest of the .c files */
		while(_findnext(hFile, &c_file)==0)
		{
			if(DecodeImage(c_file.name))
			{
				of.write((char*)"Hej\0",5);
			}
		}
		_findclose( hFile );
	}


	of.close();

/*
	DecodeImage("E:\\My Intranet\\viktor_dns2go_test\\dbs.galeforcef1.com\\photo\\1004b.jpg");
	if(image_type!=unknown)
	{
		cout << "Image Type\t" << image_type << endl;
		cout << "Image Height\t" << image_height << endl;
		cout << "Image Width\t" << image_widht << endl;
		cout << "Color Depth\t" << image_depth << endl;
	}*/
}

bool DecodeImage(char* filename2)
{
ifstream f;
//ofstream of;
	char* filename;
	filename=new char[260];
	strcpy(filename,"E:\\My Intranet\\viktor_dns2go_test\\dbs.galeforcef1.com\\photo\\");
	strcat(filename,filename2);

	unsigned char* buffer;
	buffer=new unsigned char[BUFFERSIZE];
	
	f.open(filename,ios::in|ios::binary);
	f.seekg(0,ios::beg);
	f.read((unsigned char*)buffer,BUFFERSIZE);
	image_type=unknown;
	if((buffer[0]==137)&&(buffer[1]==80)&&(buffer[2]==78))
	{
		//PNG
		image_type=png;
		switch(buffer[25])
		{
			case 0:
				image_depth=buffer[24];
				break;
			case 2:
				image_depth=buffer[24]*3;
				break;
			case 3:
				image_depth=8;
				break;
			case 4:
				image_depth=buffer[24]*2;
				break;
			case 6:
				image_depth=buffer[24]*4;
				break;
			default:
				image_type=unknown;
				break;
		}
		if(image_type!=unknown)
		{
			image_widht=Mult(buffer[19],buffer[18]);
			image_height=Mult(buffer[23],buffer[22]);
		}
	}
	else if((buffer[0]==71)&&(buffer[1]==73)&&(buffer[2]==70))
	{
		//GIF
		image_type=gif;
		image_widht=Mult(buffer[6],buffer[7]);
		image_height=Mult(buffer[8],buffer[9]);
		image_depth=(buffer[10] & 7)+1;
	}
	else if((buffer[0]==66)&&(buffer[1]==77))
	{
		//BMP
		image_type=bmp;
		image_widht=Mult(buffer[18],buffer[19]);
		image_height=Mult(buffer[22],buffer[23]);
		image_depth=buffer[28];
	}
	if(image_type==unknown)
	{
		//if the file is not one of the above type then
		//check to see if it is a jpeg file
		int iPos=0;
		int iTmp=0;
		
		//||(iPos<=BUFFERSIZE-10));
		while(((buffer[iPos++]!=0xFF)&&(buffer[iPos+1]!=0xD8)&&(buffer[iPos+2]!=0xFF)));
		iPos+=1;
		if(!(iPos>=BUFFERSIZE-10))
		{
			do
			{
				while((buffer[iPos]!=0xFF)&&(buffer[iPos+1]==0xFF))
				{
					iPos++;
				};
				iPos++;
				iTmp=buffer[iPos];
				
				if(((iTmp>=0xC0)&&(iTmp<=0xC3))||
					((iTmp>=0xC5)&&(iTmp<=0xC7))||
					((iTmp>=0xC9)&&(iTmp<=0xCB))||
					((iTmp>=0xCD)&&(iTmp<=0xCF)))
				{
					image_type=jpg;
					image_depth=buffer[iPos+8]*8;
					image_height=Mult(buffer[iPos+5],buffer[iPos+4]);
					image_widht=Mult(buffer[iPos+7],buffer[iPos+6]);
					break;
				}
				iPos+=Mult(buffer[iPos+2],buffer[iPos+1]);
			}while(iPos<BUFFERSIZE-10);
		}
	}
	f.close();
	delete[] buffer;
	if(image_type!=unknown)
		return(true);
	else
		return(false);
}

int Mult(int a, int b)
{
	return(a+(b*256));
}
