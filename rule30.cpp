#include "rule30.h"
using namespace std;

rule30::rule30(int size){
	sizex = size;
	sizey = size;
}
vector<vector<int> > rule30::generate(){
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