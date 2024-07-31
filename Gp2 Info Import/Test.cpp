// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fstream.h"

struct structgp2data
{
	char laps;
	unsigned short len;
	unsigned short ware;
	char country[30];
	char adjective[30];
	char name[30];
};

int main(int argc, char* argv[])
{
ifstream fin;
int i;

char tName[3000];

structgp2data gp2data[16];

fin.open("gp2.exe",ios::in|ios::out|ios::binary|ios::nocreate);
	cout<<"\nGp2 Quick Info (C) Viktor Gars 2000";
	if(!fin.is_open())
	{
		cout<<"\n\nGp2.exe not found. You must run this program in your Gp2 directory.\n";
		return(0);
	}

	//Import laps
	fin.seekg(1951848,ios::beg);
	for(i=0;i<16;i++)
		fin.read((char*)&gp2data[i].laps,sizeof(char));

	//import length
	fin.seekg(1953837,ios::beg);
	for(i=0;i<16;i++)
	{
		fin.read((char*)&gp2data[i].len,sizeof(unsigned short));
		gp2data[i].len/=3.28212677519917;
		fin.seekg(5,ios::cur);
	}
	
	//import tyre ware
	fin.seekg(1280584,ios::beg);
	for(i=0;i<16;i++)	
		fin.read((char*)&gp2data[i].ware,sizeof(unsigned short));

	fin.seekg(5682445,ios::beg);
	fin.read((char*)&tName,sizeof(tName));


	int c=0;
	int tmp;
	//import track name
	for(i=0;i<16;i++)
	{
		tmp=0;
		do
		{
			gp2data[i].name[tmp]=tName[c];
			c++;
			tmp++;
		}while(tName[c]!=0);
		gp2data[i].name[tmp]='\0';
		c++;
	}

	c+=16;
	//import country name
	for(i=0;i<16;i++)
	{
		tmp=0;
		do
		{
			gp2data[i].country[tmp]=tName[c];
			c++;
			tmp++;
		}while(tName[c]!=0);
		gp2data[i].country[tmp]='\0';
		c++;
	}

	//find country name 5 more times but dont do anything with it
	for(int k=0;k<4;k++)
	{
		c+=16;
		for(i=0;i<16;i++)
		{
			tmp=0;
			do
			{
				c++;
			}while(tName[c]!=0);
			c++;
		}
	}

	c+=16;
	//import adjective
	for(i=0;i<16;i++)
	{
		tmp=0;
		do
		{
			gp2data[i].adjective[tmp]=tName[c];
			c++;
			tmp++;
		}while(tName[c]!=0);
		gp2data[i].adjective[tmp]='\0';
		c++;
	}

	cout<<"\n\n";
	cout<<"Track, Track Name, Track Country, Track Adjective, Laps, Length, Tyre Ware\n\n";
	for(i=0;i<16;i++)
	{
		cout<< "Track "<<i+1<<": " << gp2data[i].name << ", "<<gp2data[i].country << ", "<<gp2data[i].adjective <<", " << (int)(gp2data[i].laps) <<" laps, "<< gp2data[i].len <<"m, "<< gp2data[i].ware<<" ware\n";
	}

	return(0);
}

