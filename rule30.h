#include <cstdlib>
#include <time.h>
#include <gd.h>
#include <stdio.h>
#include <vector>
using namespace std;
class rule30{
	private:
		int sizex, sizey;
	public:
		rule30(int size);
		vector<vector<int> > generate();
};