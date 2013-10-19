#include "graphics.h"
#include <iostream>
using namespace std;

void graphics::renderca(vector<vector<int> > ca, string path){
	gdImagePtr img = gdImageCreate(ca[0].size(), ca.size());
	int white = gdImageColorAllocate(img, 255, 255, 255);
	int black = gdImageColorAllocate(img, 0, 0, 0);
	FILE *out;
	for(int j = 0; j < ca.size(); j++){
		for(int i = 0; i < ca[0].size(); i++){
			if(ca[i][j]) gdImageSetPixel(img, i, j, black);
		}
	}
	out = fopen(path.c_str(), "wb"); //wb for windows portability
	gdImagePng(img, out);
	fclose(out);
	gdImageDestroy(img);
}

void graphics::renderca(vector<vector<int> > ca, complex* width, string path){
	gdImagePtr img = gdImageCreate((width->y - width->x), ca.size());
	int white = gdImageColorAllocate(img, 255, 255, 255);
	int black = gdImageColorAllocate(img, 0, 0, 0);
	FILE *out;
	for(int j = 0; j < ca.size(); j++){
		for(int i = width->x; i < width->y; i++){
			if(ca[i][j]){
				gdImageSetPixel(img, (i - width->x), j, black);
			}
		}
	}
	out = fopen(path.c_str(), "wb"); //wb for windows portability
	gdImagePng(img, out);
	fclose(out);
	gdImageDestroy(img);
}