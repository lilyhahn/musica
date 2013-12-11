#include "song.h"
#include <iostream>
#include <unistd.h>
#include "chord.h"
using namespace std;

int main(int argc, char **argv){
	int key = 0;
	if(argv[1] != NULL){
		key = atoi(argv[1]);
	}
	Chord chord = Chord(Note(key));
	cout << "Generated a " << chord.getRoot().toString() << " major chord. The third is " <<
	chord.getThird().toString() << " and the fifth is " << chord.getFifth().toString() << endl;
	Rule30 ca = Rule30(40);
	vector<vector<int> > soup = ca.getData();
	ca.render("rule30.png");
	//graphics::renderca(soup, (new complex(20, 40)), "range.png");
	ca.constrain((complex(20, 32)));
	ca.render("range.png");
	Song* song = new Song(ca, 120, Note(key));
	song->renderData("song.png");
	song->play();
	/*sleep(10);
	song->changeKey(Note::G);
	song->render("songg.png");*/
	delete song; //very important!
}