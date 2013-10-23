#include <vector>
#include "key.h"
using namespace std;

class Song{
	vector<Note> allowedNotes;
	vector<vector<int> > data;
	void fitKey(Note key);
	public:
		Song(vector<vector<int> > d, Note key);
};