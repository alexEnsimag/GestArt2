#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //Set the application frame rate to 30 FPS
    ofSetFrameRate( 30 );

    //old OF default is 96 - but this results in fonts looking larger than in other programs.
	/*ofTrueTypeFont::setGlobalDpi(72);

    //Load the font for the info messages
	font.loadFont("verdana.ttf", 18, true, true);
	font.setLineHeight(18.0f);
	font.setLetterSpacing(1.037);*/

    //Open the connection with Synapse
    synapseStreamer.openSynapseConnection();

    //Set which joints we want to track
    synapseStreamer.trackAllJoints(false);
    synapseStreamer.trackLeftHand(true);
    synapseStreamer.trackRightHand(true);
    synapseStreamer.computeHandDistFeature(true);

    //Setup the graphs for the input data
    //setupGraphs();

    //infoText = "";

    //Setup the training data
    /*trainingData.setNumDimensions( 6 );
    trainingModeActive = false;
    predictionModeActive = false;
    trainingClassLabel = 1;*/

    //Setup the classifier
    /*ANBC anbc;
    anbc.enableNullRejection(true);
    anbc.setNullRejectionCoeff(5);
    pipeline.setClassifier( anbc );*/

}

//--------------------------------------------------------------
void testApp::update(){

    //Parse any new messages from the synapse streamer
    synapseStreamer.parseIncomingMessages();

    if( synapseStreamer.getNewMessage() ){

        //Get the left hand and right hand joings
        leftHand = synapseStreamer.getLeftHandJointBody();
        rightHand = synapseStreamer.getRightHandJointBody();

        //Update the graphs
        /*leftHandGraph.update( leftHand );
        rightHandGraph.update( rightHand );*/

        vector< double > inputVector(6);
        inputVector[0] = leftHand[0];
        inputVector[1] = leftHand[1];
        inputVector[2] = leftHand[2];
        inputVector[3] = rightHand[0];
        inputVector[4] = rightHand[1];
        inputVector[5] = rightHand[2];

        /*if( trainingModeActive ){

            if( trainingTimer.getInRecordingMode() ){
                trainingData.addSample(trainingClassLabel, inputVector);
            }

            if( trainingTimer.getRecordingStopped() ){
                trainingModeActive = false;
            }
        }

        if( pipeline.getTrained() ){
            if( !pipeline.predict(inputVector) ){
                infoText = "Failed to make prediction";
            }
        }*/
    }

}

//--------------------------------------------------------------
/*void testApp::draw(){
    ofBackground(0,0,0);

    unsigned int x = 20;
    unsigned int y = 20;
    unsigned int graphWidth = TIME_SERIES_GRAPH_WIDTH;
    unsigned int graphHeight = 100;
    ofRectangle fontBox;
    string text;

    //Draw the timeseries graphs
    leftHandGraph.draw(x,y,graphWidth,graphHeight);
    ofSetColor(255, 255, 255);
    text = "Left Hand";
    fontBox = font.getStringBoundingBox(text, 0, 0);
    font.drawString(text, x+(graphWidth/2)-(fontBox.width/2), y+10);
    y += graphHeight + 20;

    rightHandGraph.draw(x,y,graphWidth,graphHeight);
    ofSetColor(255, 255, 255);
    text = "Right Hand";
    fontBox = font.getStringBoundingBox(text, 0, 0);
    font.drawString(text, x+(graphWidth/2)-(fontBox.width/2), y+10);
    y += graphHeight + 20;


    int textX = 20;
    int textY = y;
    int textSpacer = 20;

    //Draw the training info
    ofSetColor(255, 255, 255);
    text = "------------------- TrainingInfo -------------------";
    font.drawString(text,textX,textY);

    textY += textSpacer;
    if( trainingModeActive ){
        if( trainingTimer.getInPrepMode() ){
            ofSetColor(255, 200, 0);
            text = "PrepTime: " + ofToString(trainingTimer.getSeconds());
        }
        if( trainingTimer.getInRecordingMode() ){
            ofSetColor(255, 0, 0);
            text = "RecordTime: " + ofToString(trainingTimer.getSeconds());
        }
    }else text = "Not Recording";
    font.drawString(text,textX,textY);

    ofSetColor(255, 255, 255);
    textY += textSpacer;
    text = "TrainingClassLabel: " + ofToString(trainingClassLabel);
    font.drawString(text,textX,textY);

    textY += textSpacer;
    text = "NumTrainingSamples: " + ofToString(trainingData.getNumSamples());
    font.drawString(text,textX,textY);


    //Draw the prediction info
    textY += textSpacer*2;
    text = "------------------- Prediction Info -------------------";
    font.drawString(text,textX,textY);

    textY += textSpacer;
    text =  pipeline.getTrained() ? "Model Trained: YES" : "Model Trained: NO";
    font.drawString(text,textX,textY);

    textY += textSpacer;
    text = "PredictedClassLabel: " + ofToString(pipeline.getPredictedClassLabel());
    font.drawString(text,textX,textY);

    textY += textSpacer;
    text = "Likelihood: " + ofToString(pipeline.getMaximumLikelihood());
    font.drawString(text,textX,textY);


    //Draw the info text
    textY += textSpacer*2;
    text = "InfoText: " + infoText;
    font.drawString(text,textX,textY);


    //Draw the prediction boxes
    double boxX = textX;
    double boxY = textY + (textSpacer*2);
    double boxSize = 50;
    vector< UINT > classLabels = pipeline.getClassLabels();
    for(unsigned int i=0; i<pipeline.getNumClasses(); i++){
        if( pipeline.getPredictedClassLabel() == classLabels[i] ){
            ofSetColor(255,255,0);
            ofFill();
            ofRect(boxX, boxY, boxSize, boxSize);
        }

        ofSetColor(255,255,255);
        ofNoFill();
        ofRect(boxX, boxY, boxSize, boxSize);
        boxX += boxSize + 10;
    }

}*/

//--------------------------------------------------------------
/*void testApp::keyPressed(int key){

    infoText = "";

    switch( key ){
        case 'q':
            synapseStreamer.openOutgoingConnection();
            break;
        case 'r':
            trainingModeActive = !trainingModeActive;
            if( trainingModeActive ){
                trainingTimer.startRecording(DEFAULT_PREP_TIME, DEFAULT_RECORD_TIME);
            }else trainingTimer.stopRecording();
            break;
        case '[':
            if( trainingClassLabel > 1 )
                trainingClassLabel--;
            break;
        case ']':
            trainingClassLabel++;
            break;
        case 't':
            if( pipeline.train( trainingData ) ){
                infoText = "Pipeline Trained";
            }else infoText = "WARNING: Failed to train pipeline";
            break;
        case 's':
            if( trainingData.saveDatasetToFile("TrainingData.txt") ){
                infoText = "Training data saved to file";
            }else infoText = "WARNING: Failed to save training data to file";
            break;
        case 'l':
            if( trainingData.loadDatasetFromFile("TrainingData.txt") ){
                infoText = "Training data saved to file";
            }else infoText = "WARNING: Failed to load training data from file";
            break;
        case 'c':
            trainingData.clear();
            infoText = "Training data cleared";
            break;
        default:
            printf("Key Pressed: %i\n",key);
            break;
    }

}*/

//--------------------------------------------------------------
/*void testApp::keyReleased(int key){

}*/

//--------------------------------------------------------------
/*void testApp::mouseMoved(int x, int y ){

}*/

//--------------------------------------------------------------
/*void testApp::mouseDragged(int x, int y, int button){

}*/

//--------------------------------------------------------------
/*void testApp::mousePressed(int x, int y, int button){

}*/

//--------------------------------------------------------------
/*void testApp::mouseReleased(int x, int y, int button){

}*/

//--------------------------------------------------------------
/*void testApp::windowResized(int w, int h){

}*/

//--------------------------------------------------------------
/*void testApp::gotMessage(ofMessage msg){

}*/

//--------------------------------------------------------------
/*void testApp::dragEvent(ofDragInfo dragInfo){

}*/

/*void testApp::exit(){

}*/

/*void testApp::setupGraphs(){

    vector< ofColor > axisColors(3);
    axisColors[0] = ofColor(255,0,0);
    axisColors[1] = ofColor(0,255,0);
    axisColors[2] = ofColor(0,0,255);

    leftHandGraph.init(TIME_SERIES_GRAPH_WIDTH, 3);
    leftHandGraph.backgroundColor = ofColor(0,0,0);
    leftHandGraph.gridColor = ofColor(200,200,200,100);
    leftHandGraph.drawGrid = true;
    leftHandGraph.drawInfoText = false;
    leftHandGraph.setRanges( vector<double>(3,0), vector<double>(3,1) );
    leftHandGraph.colors = axisColors;

    rightHandGraph.init(TIME_SERIES_GRAPH_WIDTH, 3);
    rightHandGraph.backgroundColor = ofColor(0,0,0);
    rightHandGraph.gridColor = ofColor(200,200,200,100);
    rightHandGraph.drawGrid = true;
    rightHandGraph.drawInfoText = false;
    rightHandGraph.setRanges( vector<double>(3,0), vector<double>(3,1) );
    rightHandGraph.colors = axisColors;
}*/

