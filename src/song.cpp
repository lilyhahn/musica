#include "song.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;

Song::Song(vector<vector<int> > d, Note key){
	data = d;
	startData = d;
	changeKey(key);
	engine = irrklang::createIrrKlangDevice();
}
Song::Song(Rule30 ca, Note key){
	data = ca.getData();
	startData = ca.getData();
	changeKey(key);
	engine = irrklang::createIrrKlangDevice();
}
Song::Song(Rule30 ca, int bpm_, Note key){
	if(bpm_ > MIN_BPM){
		bpm = bpm_;
	}
	else bpm = 60;
	data = ca.getData();
	startData = ca.getData();
	changeKey(key);
	engine = irrklang::createIrrKlangDevice();
}
Song::~Song(){
	engine->drop();
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
			
			/*allowedChords.push_back(Chord::C);
			allowedChords.push_back(Chord::F);
			allowedChords.push_back(Chord::G);*/
		}
		else if(key == Note::G){
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
			
			/*allowedChords.push_back(Chord::G);
			allowedChords.push_back(Chord::C);
			allowedChords.push_back(Chord::D);*/
		}
		else if(key == Note::D){
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
			
			/*allowedChords.push_back(Chord::D);
			allowedChords.push_back(Chord::G);
			allowedChords.push_back(Chord::A);*/
		}
		else if(key == Note::A){
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::Gs);
			
			/*allowedChords.push_back(Chord::A);
			allowedChords.push_back(Chord::D);
			allowedChords.push_back(Chord::E);*/
		}
		else if(key == Note::E){
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::Gs);
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
			allowedNotes.push_back(Note::Ds);
			
			/*allowedChords.push_back(Chord::E);
			allowedChords.push_back(Chord::A);
			allowedChords.push_back(Chord::B);*/
		}
		else if(key == Note::B){
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
			allowedNotes.push_back(Note::Ds);
			allowedNotes.push_back(Note::E);
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::Gs);
			allowedNotes.push_back(Note::As);
			
			/*allowedChords.push_back(Chord::B);
			allowedChords.push_back(Chord::E);
			allowedChords.push_back(Chord::Fs);*/
		}
		else if(key == Note::Fs){
			allowedNotes.push_back(Note::Fs);
			allowedNotes.push_back(Note::Gs);
			allowedNotes.push_back(Note::As);
			allowedNotes.push_back(Note::B);
			allowedNotes.push_back(Note::Cs);
			allowedNotes.push_back(Note::Ds);
			allowedNotes.push_back(Note::F);
			
			/*allowedChords.push_back(Chord::Fs);
			allowedChords.push_back(Chord::B);
			allowedChords.push_back(Chord::Df);*/
		}
		else if(key == Note::Df){
			allowedNotes.push_back(Note::Df);
			allowedNotes.push_back(Note::Ef);
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::Gf);
			allowedNotes.push_back(Note::Af);
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
			
			/*allowedChords.push_back(Chord::Df);
			allowedChords.push_back(Chord::Fs);
			allowedChords.push_back(Chord::Af);*/
		}
		else if(key == Note::Af){
			allowedNotes.push_back(Note::Af);
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::Df);
			allowedNotes.push_back(Note::Ef);
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::G);
			
			/*allowedChords.push_back(Chord::Af);
			allowedChords.push_back(Chord::Df);
			allowedChords.push_back(Chord::Ef);*/
		}
		else if(key == Note::Ef){
			allowedNotes.push_back(Note::Ef);
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::Af);
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::D);
			
			/*allowedChords.push_back(Chord::Ef);
			allowedChords.push_back(Chord::Af);
			allowedChords.push_back(Chord::Bf);*/
		}
		else if(key == Note::Bf){
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::Ef);
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::A);
			
			/*allowedChords.push_back(Chord::Bf);
			allowedChords.push_back(Chord::Ef);
			allowedChords.push_back(Chord::F);*/
		}
		else if(key == Note::F){
			allowedNotes.push_back(Note::F);
			allowedNotes.push_back(Note::G);
			allowedNotes.push_back(Note::A);
			allowedNotes.push_back(Note::Bf);
			allowedNotes.push_back(Note::C);
			allowedNotes.push_back(Note::D);
			allowedNotes.push_back(Note::E);
			
			/*allowedChords.push_back(Chord::F);
			allowedChords.push_back(Chord::Bf);
			allowedChords.push_back(Chord::C);*/
		}
		else{
			//throw exception
		}
	fitKey();
}
void Song::fitKey(){
	srand(time(NULL));
	// first pass: remove any notes that are not in the key
	for(int j = 0; j < data[0].size(); j++){
		for(int i = 0; i < data.size(); i++){
			int note = i; // start at the bottom and get higher as we go up
			if(!isInKey(Note(note))) data[i][j] = 0;
		}
	}
	//second pass: make sure all chords are thirds
	for(int j = 0; j < data[0].size(); j++){
		int lastnotepos = -1;
		for(int i = 0; i < data.size(); i++){
			/*int note = i; // start at the bottom and get higher as we go up
			if(data[i][j]){
				int continueTo = rand() % 4;
				for(int k = 0; k < allowedChords.size(); k++){
					cout << "looped " << k << " times\n";
					if(i == allowedChords[k].getRoot().value && continueTo == k){
						cout << "got chord: " << Note(i).toString() << endl;
						chordsToPlay.push_back(Chord(Note(i)));
					}
				}
			}*/
			if(data[i][j]){
				if(lastnotepos != -1){
					if(!((i - lastnotepos) % 2)){
						data[lastnotepos][j] = 0;
					}
				}
				lastnotepos = i;
			}
		}
	}
	/*cout << "dumping chords to play...\n";
	for(int i = 0; i < chordsToPlay.size(); i++){
		cout << chordsToPlay[i].getRoot().toString() << endl;
	}*/
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
void Song::play(){
	for(int j = 0; j < data[0].size(); j++){
		//cout << "looped " << j << " times\n";
		for(int i = 0; i < data.size(); i++){
			if(!data[i][j]){
				
			}
			else {
				Note note = Note(i);
				engine->play2D(note.sound.c_str(), true);
			}
		}
		float sleeptime = 60 / bpm * 1000 * 1000;
		usleep(sleeptime);
		engine->stopAllSounds();
	}
}
void Song::renderData(string path){
	Rule30 dataCA = Rule30(data);
	dataCA.render(path);
}