#include <vector>
#include "note.h"
using namespace std;

class Song{
	vector<Note> allowedNotes;
	vector<vector<int> > data;
	void fitKey();
	bool isInKey(Note note);
	public:
		Song(vector<vector<int> > d, Note key);
};