#include "Video.hpp"
#include <iostream>

using namespace std;


static void sleep2(unsigned int ms){
	clock_t goal = ms + clock();
	while(goal>clock());
}

void Video::launchVideo(string videoName, int durationMs){
	libvlc_instance_t * inst;
	libvlc_media_player_t *mp;
	libvlc_media_t *m;

	/* Load the VLC engine */
	inst = libvlc_new (0, NULL);

	/* Create a new item */
	//m = libvlc_media_new_location (inst, "Move_Kinect.avi");
	try{
		m = libvlc_media_new_path (inst, videoName.c_str());
	}catch (int e){
		cout << "Fichier non trouvé:" << videoName << endl;
		return;
	}

	/* Create a media player playing environement */
	mp = libvlc_media_player_new_from_media (m);


	/* No need to keep the media now */
	libvlc_media_release (m);

	libvlc_set_fullscreen(mp, 1); 		



	/* play the media_player */

	libvlc_media_player_play (mp);
	sleep2(durationMs*1000); /* Let it play a bit */

	/* Stop playing */
	libvlc_media_player_stop (mp);

	/* Free the media_player */
	libvlc_media_player_release (mp);

	libvlc_release (inst);

}





