
#ifndef DEF_VIDEO
#define DEF_VIDEO

#include <string>
#include <vlc/vlc.h>
#include <unistd.h>
#include <time.h>

class Video{

	public : 
		static void lancementVideo(std::string nomVideo, float dureeMs);

};

#endif
