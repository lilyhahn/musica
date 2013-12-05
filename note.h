#include <string>
#define NOTE 666
using namespace std;
/*enum Note{
	Af = 8,
	A = 9,
	As = 10,
	Bf = 10,
	B = 11,
	C = 0,
	Cs = 1,
	Df = 1,
	D = 2,
	Ds = 3,
	Ef = 3,
	E = 4,
	F = 5,
	Fs = 6,
	Gf = 6,
	G = 7,
	Gs = 8
};*/
class Note{
	public:
		string sound;
		int value;
		static Note Af, A, As, Bf, B, C, Cs, Df, D, Ds, Ef, E, F, Fs, Gf, G, Gs;
		Note(int val, string soundfile);
		Note(int val);
		Note();
		string toString();
		bool operator==(const Note &other) const{
			if(other.value == this->value) return true;
			return false;
		}
		bool operator!=(const Note &other) const{
			return !(*this == other);
		}
};

/*class NoteUtil{
	public:
		static string toString(Note note); //convert notes to strings for cfugue
};*/