#include <iostream>
using namespace std;
#include <fstream>

void WriteFile();
void ReadFile();

void main()
{
	WriteFile();
	ReadFile();
}

void WriteFile()
{
	ofstream ofs;
	ofs.open("c:\\FileTest.txt");
	ofs<< "Hej Kalle Anka Vad heter Du?";
	ofs.close();
}

void ReadFile()
{
	ifstream ifs;
	char ch;
	ifs.open("c:\\FileTest.txt");
	while(ifs.get(ch))
		cout << ch;
	ifs.close();
	cout << endl;
}