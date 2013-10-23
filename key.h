enum Note{
	A = 0,
	B,
	C,
	D,
	E,
	F,
	G
};

enum Accidental{
	flat = 0,
	natural,
	sharp
};

class Key{
	public:
	Key(Note key, Accidental accidental);
}