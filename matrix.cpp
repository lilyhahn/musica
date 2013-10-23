#include "matrix.h"
using namespace std;

//fixed

vector<vector<int> > Matrix::constrain(vector<vector<int> > m, complex range){
	vector<vector<int> > out;
	out.resize(range.y-range.x);
	for(int i = range.x; i < range.y; i++) out[i-range.x].resize(m.size()); // resize first to avoid overwriting data
	for(int j = 0; j < m.size(); j++){
		for(int i = range.x; i < range.y; i++){
			out[i-range.x][j] = m[i][j];
		}
	}
	return out;
}