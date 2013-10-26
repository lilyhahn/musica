#include "song.h"
#include <iostream>
using namespace std;

Song::Song(vector<vector<int> > d, Note key){
	switch(key){ //only major keys right now
		case C:
			allowedNotes.push_back(C);
			allowedNotes.push_back(D);
			allowedNotes.push_back(E);
			allowedNotes.push_back(F);
			allowedNotes.push_back(G);
			allowedNotes.push_back(A);
			allowedNotes.push_back(B);
			break;
		case G:
			allowedNotes.push_back(G);
			allowedNotes.push_back(A);
			allowedNotes.push_back(B);
			allowedNotes.push_back(C);
			allowedNotes.push_back(D);
			allowedNotes.push_back(E);
			allowedNotes.push_back(Fs);
			break;
		case D:
			allowedNotes.push_back(D);
			allowedNotes.push_back(E);
			allowedNotes.push_back(Fs);
			allowedNotes.push_back(G);
			allowedNotes.push_back(A);
			allowedNotes.push_back(B);
			allowedNotes.push_back(Cs);
			break;
		case A:
			allowedNotes.push_back(A);
			allowedNotes.push_back(B);
			allowedNotes.push_back(Cs);
			allowedNotes.push_back(D);
			allowedNotes.push_back(E);
			allowedNotes.push_back(Fs);
			allowedNotes.push_back(Gs);
			break;
		case E:
			allowedNotes.push_back(E);
			allowedNotes.push_back(Fs);
			allowedNotes.push_back(Gs);
			allowedNotes.push_back(A);
			allowedNotes.push_back(B);
			allowedNotes.push_back(Cs);
			allowedNotes.push_back(Ds);
			break;
		case B:
			allowedNotes.push_back(B);
			allowedNotes.push_back(Cs);
			allowedNotes.push_back(Ds);
			allowedNotes.push_back(E);
			allowedNotes.push_back(Fs);
			allowedNotes.push_back(Gs);
			allowedNotes.push_back(As);
			break;
		case Fs:
			allowedNotes.push_back(Fs);
			allowedNotes.push_back(Gs);
			allowedNotes.push_back(As);
			allowedNotes.push_back(B);
			allowedNotes.push_back(Cs);
			allowedNotes.push_back(Ds);
			allowedNotes.push_back(Es);
			break;
		case Df:
			allowedNotes.push_back(Df);
			allowedNotes.push_back(Ef);
			allowedNotes.push_back(F);
			allowedNotes.push_back(Gf);
			allowedNotes.push_back(Af);
			allowedNotes.push_back(Bf);
			allowedNotes.push_back(C);
			break;
		case Af:
			allowedNotes.push_back(Af);
			allowedNotes.push_back(Bf);
			allowedNotes.push_back(C);
			allowedNotes.push_back(Df);
			allowedNotes.push_back(Ef);
			allowedNotes.push_back(F);
			allowedNotes.push_back(G);
			break;
		case Ef:
			allowedNotes.push_back(Ef);
			allowedNotes.push_back(F);
			allowedNotes.push_back(G);
			allowedNotes.push_back(Af);
			allowedNotes.push_back(Bf);
			allowedNotes.push_back(C);
			allowedNotes.push_back(D);
			break;
		case Bf:
			allowedNotes.push_back(Bf);
			allowedNotes.push_back(C);
			allowedNotes.push_back(D);
			allowedNotes.push_back(Ef);
			allowedNotes.push_back(F);
			allowedNotes.push_back(G);
			allowedNotes.push_back(A);
			break;
		case F:
			allowedNotes.push_back(F);
			allowedNotes.push_back(G);
			allowedNotes.push_back(A);
			allowedNotes.push_back(Bf);
			allowedNotes.push_back(C);
			allowedNotes.push_back(D);
			allowedNotes.push_back(E);
			break;
		default:
			//throw exception
			break;
	}
}