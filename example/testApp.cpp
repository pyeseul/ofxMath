#include "testApp.h"
#include "ofxMath.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetVerticalSync(true);
    for(int i = 0; i < size; i++) {
        ps[i] = ofRandomScreenPoint();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    ps[size - 1] = ofRandomScreenPoint();
    for(int i = 0; i < size - 1; i++) {
//        ps[i] = ofLerp(ps[i], ps[i + 1], 0.2f * i / size + 0.2f);
        ps[i] = ofLerp(ps[i], ps[i + 1], 0.99f);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < drawSize; i++) {
//        ofSetColor(256 * (float)i / drawSize,
//                   256 * (float)i / drawSize,
//                   256 * (float)i / drawSize,
//                   256 * (float)i / drawSize);
        ofLine(ps[i], ps[i + 1]);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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
