#ifndef NOTE
	#include "note.h"
#endif

class Chord {
	private:
		Note root;
		Note third;
		Note fifth;
	public:
		Chord();
		Chord(Note r);
		Note getRoot();
		Note getThird();
		Note getFifth();
		
		static Chord C;
		static Chord Cs;
		static Chord Df;
		static Chord D;
		static Chord Ds;
		static Chord Ef;
		static Chord E;
		static Chord F;
		static Chord Fs;
		static Chord Gf;
		static Chord G;
		static Chord Gs;
		static Chord Af;
		static Chord A;
		static Chord As;
		static Chord Bf;
		static Chord B;
};