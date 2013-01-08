#pragma once

#include "ofMain.h"
#include "ofxFaceTracker.h"

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
    
    ofSoundPlayer girl1;
    ofSoundPlayer girl2;
    ofSoundPlayer girl3;
    ofSoundPlayer girl4;
    ofSoundPlayer boy1;
    ofSoundPlayer boy2;
    ofSoundPlayer boy3;
    ofSoundPlayer boy4;
    
    int picker;
    int lastPicked;
    float openMouth;
    bool soundOn;
    
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
	ExpressionClassifier classifier;
};
