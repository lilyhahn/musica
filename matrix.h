#include <vector>
#ifndef COMPLEX
	#include "complex.h"
#endif
using namespace std;

class matrix{
	public:
		static vector<vector<int> > constrain(vector<vector<int> > m, complex range);
};