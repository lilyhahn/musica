#include "song.h"
#include "graphics.h"
#include <iostream>
#include <unistd.h>
using namespace std;

Song::Song(vector<vector<int> > d, Note key){
	data = d;
	startData = d;
	changeKey(key);
}
void Song::changeKey(Note key){
	allowedNotes.clear();
	data = startData; // reset to original seed
		if(key == Note::C){
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::B);
		}
		else if(key == Note::G){
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
		}
		else if(key == Note::D){
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
		}
		else if(key == Note::A){
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::Gs);
		}
		else if(key == Note::E){
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::Gs);
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
			allowedNotes.push_back(Note::Ds);
		}
		else if(key == Note::B){
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
			allowedNotes.push_back(Note::Ds);
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::Gs);
			allowedNotes.push_back(Note::As);
		}
		else if(key == Note::Fs){
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::Gs);
			allowedNotes.push_back(Note::As);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
			allowedNotes.push_back(Note::Ds);
			allowedNotes.push_back(Note::F);
		}
		else if(key == Note::Df){
			allowedNotes.push_back(Note::Df);
			allowedNotes.push_back(Note::Ef);
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::Gf);
			allowedNotes.push_back(Note::Af);
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
		}
		else if(key == Note::Af){
			allowedNotes.push_back(Note::Af);
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::Df);
			allowedNotes.push_back(Note::Ef);
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::G);
		}
		else if(key == Note::Ef){
			allowedNotes.push_back(Note::Ef);
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::Af);
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::D);
		}
		else if(key == Note::Bf){
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::Ef);
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::A);
		}
		else if(key == Note::F){
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::E);
		}
		else{
			//throw exception
		}
	fitKey();
}
void Song::fitKey(){
	for(int j = 0; j < data[0].size(); j++){
		for(int i = 0; i < data.size(); i++){
			int note = i; // start at the bottom and get higher as we go up
			if(!isInKey(Note(note))) data[i][j] = 0;
			//this is obviously a simplified solution, if this is going to make good music this should try to make
			//chord progressions or something
		}
	}
}

bool Song::isInKey(Note note){
	for(int i = 0; i < allowedNotes.size(); i++){ //i don't feel like learning how to use iterators ok
		if(allowedNotes[i] == note){
		 	return true;
		}
	}
	return false;
}
vector<vector<int> > Song::getData(){
	return data;
}
void Song::render(string path){
	Graphics::renderca(data, path);
	irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();
		for(int j = 0; j < data[0].size(); j++){
		for(int i = 0; i < data.size(); i++){
			if(!data[i][j]){
				
			}
			else {
				Note note = Note(i);
				engine->play2D(note.sound.c_str());
			}
		}
		sleep(1);
	}
	engine->drop();
}