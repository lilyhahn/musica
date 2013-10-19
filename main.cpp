#include "graphics.h"
#include "rule30.h"
#include "matrix.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
	rule30* ca = new rule30(40);
	vector<vector<int> > soup = ca->generate();
	graphics::renderca(soup, "rule30.png");
	graphics::renderca(soup, (new complex(20, 40)), "range.png");
}