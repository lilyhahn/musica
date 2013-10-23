#include <cstdlib>
#include <time.h>
#include <gd.h>
#include <stdio.h>
#include <vector>
using namespace std;
class Rule30{
	private:
		int sizex, sizey;
	public:
		Rule30(int size);
		vector<vector<int> > generate();
};