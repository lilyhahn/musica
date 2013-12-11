#include <vector>
#include <irrKlang.h>
#include "rule30.h"
#ifndef NOTE
	#include "note.h"
#endif
#define MIN_BPM 60
using namespace std;

class Song{
	vector<Note> allowedNotes;
	//vector<Chord> allowedChords;
	//vector<Chord> chordsToPlay;
	vector<vector<int> > data;
	vector<vector<int> > startData;
	void fitKey();
	bool isInKey(Note note);
	irrklang::ISoundEngine* engine;
	float bpm = 60;
	public:
		void changeKey(Note key);
		void changeKey(Note key, bool minor);
		vector<vector<int> > getData();
		Song(vector<vector<int> > d, Note key);
		Song(Rule30 ca, Note key);
		Song(Rule30 ca, int bpm_, Note key);
		~Song();
		void play();
		void renderData(string path);
};