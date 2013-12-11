#include "rule30.h"
using namespace std;

Rule30::Rule30(int size){
	sizex = size;
	sizey = size;
	data = generate();
}
Rule30::Rule30(vector<vector<int> > d){
	data = d;
}
void Rule30::render(string path){
	gdImagePtr img = gdImageCreate(data.size(), data[0].size());
	int white = gdImageColorAllocate(img, 255, 255, 255);
	int black = gdImageColorAllocate(img, 0, 0, 0);
	FILE *out;
	for(int j = 0; j < data[0].size(); j++){
		for(int i = 0; i < data.size(); i++){
			if(data[i][j]) gdImageSetPixel(img, i, j, black);
		}
	}
	out = fopen(path.c_str(), "wb"); //wb for windows portability
	gdImagePng(img, out);
	fclose(out);
	gdImageDestroy(img);
}
vector<vector<int> > Rule30::generate(){
	vector<vector<int> > world;
	world.resize(sizex);
	srand(time(NULL));
	//seed with random starting data
	for(int i = 0; i < sizex; i++){
		world[i].resize(sizey); //allocate y dimension
		world[i][0] = rand() % 2;
	}
	for(int j = 1; j < sizey-1; j++){
		for(int i = 1; i < sizex-1; i++){
			//if cell in previous row is ok to make new cell, set this cell to 1
			if ( (world[i-1][j-1] == 0 && world[i][j-1] == 0 && world[i+1][j-1] == 1 ) ||
          		( world[i-1][j-1] == 0 && world[i][j-1] == 1 && world[i+1][j-1] == 0 ) ||
           		( world[i-1][j-1] == 0 && world[i][j-1] == 1 && world[i+1][j-1] == 1 ) ||
           		( world[i-1][j-1] == 1 && world[i][j-1] == 0 && world[i+1][j-1] == 0 ) ){
           			world[i][j] = 1;
           		}
           		else{
           			world[i][j] = 0;
           		}
		}
		
		//boundary conditions
		world[j][0] = world[j][sizex];
		world[j][sizex] = world[j][1];
	}
	return world;
}
void Rule30::constrain(complex range){
	vector<vector<int> > out;
	out.resize(range.y-range.x);
	for(int i = range.x; i < range.y; i++) out[i-range.x].resize(data.size()); // resize first to avoid overwriting data
	for(int j = 0; j < data.size(); j++){
		for(int i = range.x; i < range.y; i++){
			out[i-range.x][j] = data[i][j];
		}
	}
	data = out;
}
vector<vector<int> > Rule30::getData(){
	return data;
}