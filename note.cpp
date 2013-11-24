#include "note.h"
using namespace std;

Note Note::C = Note(0, "media/Piano.mf.C3.wav");
Note Note::Cs = Note(1, "media/Piano.mf.Db3.wav");
Note Note::Df = Note(1, "media/Piano.mf.Db3.wav");
Note Note::D = Note(2, "media/Piano.mf.D3.wav");
Note Note::Ds = Note(3, "media/Piano.mf.Eb3.wav");
Note Note::Ef = Note(3, "media/Piano.mf.Eb3.wav");
Note Note::E = Note(4, "media/Piano.mf.E3.wav");
Note Note::F = Note(5, "media/Piano.mf.F3.wav");
Note Note::Fs = Note(6, "media/Piano.mf.Gb3.wav");
Note Note::Gf = Note(6, "media/Piano.mf.Gb3.wav");
Note Note::G = Note(7, "media/Piano.mf.G3.wav");
Note Note::Gs = Note(8, "media/Piano.mf.Ab3.wav");
Note Note::Af = Note(8, "media/Piano.mf.Ab3.wav");
Note Note::A = Note(9, "media/Piano.mf.A3.wav");
Note Note::As = Note(10, "media/Piano.mf.Bb3.wav");
Note Note::Bf = Note(10, "media/Piano.mf.Bb3.wav");
Note Note::B = Note(11, "media/Piano.mf.B3.wav");

Note::Note(int val, string soundfile){
	value = val;
	sound = soundfile;
}
Note::Note(int val){
	value = val;
	switch(val){
		case 0:
			sound = "media/Piano.mf.C3.wav";
			break;
		case 1:
			sound = "media/Piano.mf.Db3.wav";
			break;
		case 2:
			sound = "media/Piano.mf.D3.wav";
			break;
		case 3:
			sound = "media/Piano.mf.Eb3.wav";
			break;
		case 4:
			sound = "media/Piano.mf.E3.wav";
			break;
		case 5:
			sound = "media/Piano.mf.F3.wav";
			break;
		case 6:
			sound = "media/Piano.mf.Gb3.wav";
			break;
		case 7:
			sound = "media/Piano.mf.G3.wav";
			break;
		case 8:
			sound = "media/Piano.mf.Ab3.wav";
			break;
		case 9:
			sound = "media/Piano.mf.A3.wav";
			break;
		case 10:
			sound = "media/Piano.mf.Bb3.wav";
			break;
		case 11:
			sound = "media/Piano.mf.B3.wav";
			break;
	}
}
/*string NoteUtil::toString(Note note){
	switch(note){
		case Af:
			return "Ab";
		case A:
			return "A";
		case As:
			return "A#";
		case B:
			return "B";
		case Bs:
			return "B#";
		case C:
			return "C";
		case Cs:
			return "C#";
		case D:
			return "D";
		case Ds:
			return "D#";
		case E:
			return "E";
		case F:
			return "F";
		case Gf:
			return "Gb";
		case G:
			return "G";
	}
}*/