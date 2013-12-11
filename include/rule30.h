#include <cstdlib>
#include <time.h>
#include <gd.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "complex.h"
using namespace std;
class Rule30{
	private:
		int sizex, sizey;
		vector<vector<int> > data;
		vector<vector<int> > generate();
	public:
		Rule30(int size);
		Rule30(vector<vector<int> > d);
		vector<vector<int> > getData();
		void render(string path);
		void constrain(complex range);
};