#include "chord.h"

Chord Chord::C = Chord(Note::C);
Chord Chord::Cs = Chord(Note::Cs);
Chord Chord::Df = Chord(Note::Cs);
Chord Chord::D = Chord(Note::D);
Chord Chord::Ds = Chord(Note::Ds);
Chord Chord::Ef = Chord(Note::Ef);
Chord Chord::E = Chord(Note::E);
Chord Chord::F = Chord(Note::F);
Chord Chord::Fs = Chord(Note::Fs);
Chord Chord::Gf = Chord(Note::Gf);
Chord Chord::G = Chord(Note::G);
Chord Chord::Gs = Chord(Note::Gs);
Chord Chord::Af = Chord(Note::Af);
Chord Chord::A = Chord(Note::A);
Chord Chord::As = Chord(Note::As);
Chord Chord::Bf = Chord(Note::As);
Chord Chord::B = Chord(Note::B);

Chord::Chord(Note r){
	root = r;
	third = Note(r.value + 2);
	fifth = Note(r.value + 4);
}

Chord::Chord(){
	root = Note::C; // if no arg assume C
	third = Note::C;
	fifth = Note::C;
}

Note Chord::getRoot(){
	return root;
}

Note Chord::getThird(){
	return third;
}

Note Chord::getFifth(){
	return fifth;
}