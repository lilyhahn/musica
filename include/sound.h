#include <irrKlang.h>

//global wrapper around irrKlang

class Sound{
	public:
		static irrklang::ISoundEngine* engine;
		static void init();
		static void drop();
		static void stopSounds();
		static void playNote(Note note);
};