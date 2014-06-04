#pragma once

#include "ofMain.h"
#include "SynapseStreamer.h"

//Inlcude the main openframeworks GRT header
#include "GRT.h"

//State that we are using the GRT namespace
using namespace GRT;

#define TIME_SERIES_GRAPH_WIDTH 500
#define DEFAULT_PREP_TIME 5000
#define DEFAULT_RECORD_TIME 5000

class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void exit();
    
    void setupGraphs();
    
    SynapseStreamer synapseStreamer;
    vector< double > leftHand;
    vector< double > rightHand;
    
    //GRT::TimeSeriesGraph leftHandGraph;
    //GRT::TimeSeriesGraph rightHandGraph;
    
    string infoText;
    ofTrueTypeFont	font;
    
    GestureRecognitionPipeline pipeline;
    LabelledClassificationData trainingData;
    TrainingDataRecordingTimer trainingTimer;
    bool trainingModeActive;
    bool predictionModeActive;
    UINT trainingClassLabel;
    
};
