#include "testApp.h"

//unsure
using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void testApp::setup(){
    //setup screen
    ofBackground(0);
    ofSetFullscreen(true);
    
    //load sound files
    girl1.loadSound("girl1.wav");
    girl2.loadSound("girl2.wav");
    girl3.loadSound("girl3.wav");
    girl4.loadSound("girl4.wav");
    boy1.loadSound("boy1.wav");
    boy2.loadSound("boy2.wav");
    boy3.loadSound("boy3.wav");
    boy4.loadSound("boy4.wav");
    
    classifier.load("expressions");
    
    //unsure
    ofSetVerticalSync(true);
	//set camera size
    cam.initGrabber(640, 480);
	
    //set up tracker
	tracker.setup();
	tracker.setRescale(.5);
}

//--------------------------------------------------------------
void testApp::update(){
    //update the camera
    cam.update();
    //if there is a new frame classify the facetracker
    if(cam.isFrameNew()) {
		if(tracker.update(toCv(cam))) {
			classifier.classify(tracker);
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    //set color so the camera is not discolored
    ofSetColor(255);
    //draw facetracker
    ofPushMatrix();
    ofTranslate(500, 200);
	//draw camera feed
//    cam.draw(0, 0);
    tracker.draw();
    ofPopMatrix();
    
    
    //the part i dont understand....
    int w = 100, h = 12;
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(5, 10);
	int n = classifier.size();
	int primary = classifier.getPrimaryExpression();
    for(int i = 0; i < n-1; i++){
		ofSetColor(i == primary ? ofColor::red : ofColor::black);
//		ofRect(0, 0, w * classifier.getProbability(i) + .5, h);
    }
    for(int i = 0; i < n; i++){
		ofSetColor(255);
//		ofDrawBitmapString(classifier.getDescription(i), 5, 9);
		ofTranslate(0, h + 5);
    }
	ofPopMatrix();
	ofPopStyle();
    
//    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), ofGetWidth() - 20, ofGetHeight() - 10);
//	drawHighlightString(
//                        string() +
//                        "r - reset\n" +
//                        "e - add expression\n" +
//                        "a - add sample\n" +
//                        "s - save expressions\n"
//                        "l - load expressions",
//                        14, ofGetHeight() - 7 * 12);
    
    if(girl1.getIsPlaying()){
        soundOn = true;
    }
    if(girl2.getIsPlaying()){
        soundOn = true;
    }
    if(girl3.getIsPlaying()){
        soundOn = true;
    }
    if(girl4.getIsPlaying()){
        soundOn = true;
    }
    if(boy1.getIsPlaying()){
        soundOn = true;
    }
    if(boy2.getIsPlaying()){
        soundOn = true;
    }
    if(boy3.getIsPlaying()){
        soundOn = true;
    }
    if(boy4.getIsPlaying()){
        soundOn = true;
    }
    
    if(girl1.getIsPlaying() == false && girl2.getIsPlaying() == false && girl3.getIsPlaying() == false && girl4.getIsPlaying() == false && boy1.getIsPlaying() == false && boy2.getIsPlaying() == false && boy3.getIsPlaying() == false && boy4.getIsPlaying() == false){
        soundOn = false;
    }
    
    if(classifier.getProbability(0) > .99999 && soundOn == false){
        //play a random yawn, make sure the same sound is not played twice
        picker = int(ofRandom(1, 9));
        if(picker == lastPicked){
            picker = int(ofRandom(1, 9));
        }
        lastPicked = picker;
        if(picker == 1){
            girl1.play();
        }
        if(picker == 2){
            girl2.play();
        }
        if(picker == 3){
            girl3.play();
        }
        if(picker == 4){
            girl4.play();
        }
        if(picker == 5){
            boy1.play();
        }
        if(picker == 6){
            boy2.play();
        }
        if(picker == 7){
            boy3.play();
        }
        if(picker == 8){
            boy4.play();
        }
    }

    cout << soundOn << endl;
//    ofDrawBitmapString(ofToString(classifier.getProbability(0)), ofGetHeight() - 30, 10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
        
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key == 'r') {
		tracker.reset();
		classifier.reset();
	}
	if(key == 'e') {
		classifier.addExpression();
	}
	if(key == 'a') {
		classifier.addSample(tracker);
	}
	if(key == 's') {
		classifier.save("expressions");
	}
	if(key == 'l') {
		classifier.load("expressions");
	}

    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}