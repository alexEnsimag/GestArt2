
#include "Scenario.hpp"
using namespace std;

void Scenario::addActivite(Activite *a){
	activites.push_back(a);
}

void Scenario::enregistrer(){
	string nomFichier = "Scenario/" + name + ".txt";
	ofstream fichier(nomFichier.c_str(), ios::out | ios::trunc);
	if(!fichier){
		cout << "Erreur a la création du Fichier" << endl;
		return;
	}
	fichier << name << endl;
	for(int i=0; i<activites.size(); i++){
		fichier << activites[i]->getName() << endl;
		fichier << activites[i]->getParam() << endl;
		fichier << activites[i]->getEssais() << endl;
	}
	fichier.close();
}

void Scenario::charger(string nomFichier){
	//Ouverture du fichier
	ifstream fichier(nomFichier.c_str(), ios::in);
	if(!fichier){
		cout << "Erreur à l'ouverture du Fichier" << endl;
		return;
	}
	string mot;
	string param;
	fichier >> mot;
	setName(mot);
	int nbEssai;


	while(!fichier.eof()){
		fichier >> mot >> param >> nbEssai;
		if (mot == "ActiviteObjet"){
			addActivite(new ActiviteObjet(param, nbEssai));
		}else if (mot == "ActiviteForme"){
			addActivite(new ActiviteForme(param, nbEssai));
		}else{
			cout << "Activitée non reconnue" << endl;
		}
	}
	//On enleve le doublon de fin
	activites.pop_back();
	fichier.close();
}

void Scenario::setName(string s){
	name = s;
}

string Scenario::getName(){
	return name;
}


	static gboolean
bus_call (GstBus     *bus,
		GstMessage *msg,
		gpointer    data)
{
	GMainLoop *loop = (GMainLoop *) data;

	switch (GST_MESSAGE_TYPE (msg)) {

		case GST_MESSAGE_EOS:
			g_print ("End of stream\n");
			g_main_loop_quit (loop);
			break;

		case GST_MESSAGE_ERROR: {
						gchar  *debug;
						GError *error;

						gst_message_parse_error (msg, &error, &debug);
						g_free (debug);

						g_printerr ("Error: %s\n", error->message);
						g_error_free (error);

						g_main_loop_quit (loop);
						break;
					}
		default:
					break;
	}

	return TRUE;
}


	static void
on_pad_added (GstElement *element,
		GstPad     *pad,
		gpointer    data)
{
	GstPad *sinkpad;
	GstElement *decoder = (GstElement *) data;

	/* We can now link this pad with the vorbis-decoder sink pad */
	g_print ("Dynamic pad created, linking demuxer/decoder\n");

	sinkpad = gst_element_get_static_pad (decoder, "sink");

	gst_pad_link (pad, sinkpad);

	gst_object_unref (sinkpad);
}

static void lancementVideoDebut(const char *uri){

	GMainLoop *loop;

	GstElement *pipeline, *source, *demuxer, *decoder, *conv, *sink;
	GstBus *bus;
	guint bus_watch_id;

	/* Initialisation */
	gst_init (NULL,NULL);

	loop = g_main_loop_new (NULL, FALSE);


	/* Create gstreamer elements */
	pipeline = gst_pipeline_new ("audio-player");
	source   = gst_element_factory_make ("filesrc",       "file-source");
	demuxer  = gst_element_factory_make ("oggdemux",      "ogg-demuxer");
	decoder  = gst_element_factory_make ("vorbisdec",     "vorbis-decoder");
	conv     = gst_element_factory_make ("audioconvert",  "converter");
	sink     = gst_element_factory_make ("autoaudiosink", "audio-output");

	if (!pipeline || !source || !demuxer || !decoder || !conv || !sink) {
		g_printerr ("One element could not be created. Exiting.\n");
	}

	/* Set up the pipeline */

	/* we set the input filename to the source element */
	
	g_object_set(G_OBJECT(source), "uri", uri, NULL);

	/* we add a message handler */
	bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
	bus_watch_id = gst_bus_add_watch (bus, bus_call, loop);
	gst_object_unref (bus);

	/* we add all elements into the pipeline */
	/* file-source | ogg-demuxer | vorbis-decoder | converter | alsa-output */
	gst_bin_add_many (GST_BIN (pipeline),
			source, demuxer, decoder, conv, sink, NULL);

	/* we link the elements together */
	/* file-source -> ogg-demuxer ~> vorbis-decoder -> converter -> alsa-output */
	gst_element_link (source, demuxer);
	gst_element_link_many (decoder, conv, sink, NULL);
	g_signal_connect (demuxer, "pad-added", G_CALLBACK (on_pad_added), decoder);

	/* note that the demuxer will be linked to the decoder dynamically.
	   The reason is that Ogg may contain various streams (for example
	   audio and video). The source pad(s) will be created at run time,
	   by the demuxer when it detects the amount and nature of streams.
	   Therefore we connect a callback function which will be executed
	   when the "pad-added" is emitted.*/



	/* Iterate */
	g_print ("Running...\n");
	g_main_loop_run (loop);


	/* Out of the main loop, clean up nicely */
	g_print ("Returned, stopping playback\n");
	gst_element_set_state (pipeline, GST_STATE_NULL);

	g_print ("Deleting pipeline\n");
	gst_object_unref (GST_OBJECT (pipeline));
	g_source_remove (bus_watch_id);
	g_main_loop_unref (loop);

}


void Scenario::launch(){
	// lancement video debut
	/*gst_init(NULL, NULL);	
	const char *nameVideo = "file://Move_Kinect.avi";
	lancementVideoDebut(nameVideo);*/

	// lancment processing et of
	of = new Of();
	of->lancementOfRecognize();

	for(int i=0; i<activites.size(); i++){
		cout<<activites[i]->getName()<<", "<<activites[i]->getParam()<<endl;
		activites[i]->launch();
	}
	killOf();
}

int Scenario::getNbActivite(){
	return activites.size();
}

Activite* Scenario::getActivite(int i){
	return(activites[i]);
}

void Scenario::removeActivite(int i){
	activites.erase(activites.begin()+i);
}

void Scenario::killOf(){
	of->killOf();
}


