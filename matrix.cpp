#include "matrix.h"
#include <iostream>
using namespace std;

//this is currently somewhat broken and things returned by it can't be rendered

vector<vector<int> > matrix::constrain(vector<vector<int> > m, complex range){
	cout << "range.x: " << range.x << " range.y: " << range.y << endl;
	cout << "sizeof(m): " << sizeof(m) << endl;
	vector<vector<int> > out;
	out.resize(range.y-range.x);
	cout << "out.size(): " << out.size() << endl;
	for(int j = 0; j < out.size(); j++){
		cout << "alive in j loop\n";
		for(int i = range.x; i < range.y; i++){
			cout << "j: " << j << " i: " << i << endl;
			out[i-range.x].resize(m.size());
			cout << "attempting to write " << m[i][j] << endl;
			out[i-range.x][j] = m[i][j];
			cout << "successfully wrote\n";
		}
	}
	cout << "finished\n";
	return out;
}