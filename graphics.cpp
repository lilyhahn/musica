#include "graphics.h"
#include <iostream>
using namespace std;

void Graphics::renderca(vector<vector<int> > ca, string path){
	gdImagePtr img = gdImageCreate(ca.size(), ca[0].size());
	int white = gdImageColorAllocate(img, 255, 255, 255);
	int black = gdImageColorAllocate(img, 0, 0, 0);
	FILE *out;
	for(int j = 0; j < ca[0].size(); j++){
		for(int i = 0; i < ca.size(); i++){
			if(ca[i][j]) gdImageSetPixel(img, i, j, black);
		}
	}
	out = fopen(path.c_str(), "wb"); //wb for windows portability
	gdImagePng(img, out);
	fclose(out);
	gdImageDestroy(img);
}

//no longer necessary - we can now shrink the matrices!
/*void graphics::renderca(vector<vector<int> > ca, complex* width, string path){
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
}*/