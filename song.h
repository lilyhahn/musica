#include <vector>
#include "note.h"
#include <irrKlang.h>
#define SAMPLE_RATE (44100)
using namespace std;

class Song{
	vector<Note> allowedNotes;
	vector<vector<int> > data;
	vector<vector<int> > startData;
	void fitKey();
	bool isInKey(Note note);
	public:
		void changeKey(Note key);
		void changeKey(Note key, bool minor);
		vector<vector<int> > getData();
		Song(vector<vector<int> > d, Note key);
		//void play();
		void render(string path);
};