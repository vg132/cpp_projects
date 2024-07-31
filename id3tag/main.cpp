#include <iostream>
#include "id3.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  CID3* id3;
	id3=new CID3();
  id3->LoadID3("track2.mp3");
	cout << "Artits: " << id3->GetArtist() << endl;
	cout << "Album: " << id3->GetAlbum() << endl;
	cout << "Track Title: " << id3->GetTrackTitle() << endl;	
	cout << "Track Nr: " << id3->GetTrackNum() << endl;
	cout << "Genre: " << id3->GetGenre() << endl;
	cout << "Comments: " << id3->GetComments() << endl;

  id3->LoadID3("track1.mp3");
	cout << "Artits: " << id3->GetArtist() << endl;
	cout << "Album: " << id3->GetAlbum() << endl;
	cout << "Track Title: " << id3->GetTrackTitle() << endl;	
	cout << "Track Nr: " << id3->GetTrackNum() << endl;
	cout << "Genre: " << id3->GetGenre() << endl;
	cout << "Comments: " << id3->GetComments() << endl;

  id3->LoadID3("track3.mp3");
	cout << "Artits: " << id3->GetArtist() << endl;
	cout << "Album: " << id3->GetAlbum() << endl;
	cout << "Track Title: " << id3->GetTrackTitle() << endl;	
	cout << "Track Nr: " << id3->GetTrackNum() << endl;
	cout << "Genre: " << id3->GetGenre() << endl;
	cout << "Comments: " << id3->GetComments() << endl;
	delete id3;
	return(0);
}
