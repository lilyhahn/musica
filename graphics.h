#include <gd.h>
#include <vector>
#include <string>
#include "complex.h"
using namespace std;

class graphics{
	public:
		graphics();
		static void renderca(vector<vector<int> >, string path);
		static void renderca(vector<vector<int> >, complex* width, string path);
};