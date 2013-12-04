#include <vector>
#include "note.h"
#include <irrKlang.h>
#include "rule30.h"
using namespace std;

class Song{
	vector<Note> allowedNotes;
	vector<vector<int> > data;
	vector<vector<int> > startData;
	void fitKey();
	bool isInKey(Note note);
	irrklang::ISoundEngine* engine;
	public:
		void changeKey(Note key);
		void changeKey(Note key, bool minor);
		vector<vector<int> > getData();
		Song(vector<vector<int> > d, Note key);
		Song(Rule30 ca, Note key);
		~Song();
		void play();
		void renderData(string path);
};