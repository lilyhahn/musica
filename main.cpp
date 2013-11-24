#include "graphics.h"
#include "rule30.h"
#include "matrix.h"
#include "song.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
	Rule30 ca = Rule30(40);
	vector<vector<int> > soup = ca.generate();
	Graphics::renderca(soup, "rule30.png");
	//graphics::renderca(soup, (new complex(20, 40)), "range.png");
	vector<vector<int> > range = Matrix::constrain(soup, (complex(20, 32)));
	Graphics::renderca(range, "rangeconst.png");
	Song song = Song(range, Note::C);
	song.render("songc.png");
	//song.play();
	/*song.changeKey(Note::G);
	song.render("songg.png");*/
}