#pragma once

#include "ofMain.h"
#include "ofxMath.h"

const int size = 10000;
const int drawSize = 2000;

class ofApp : public ofBaseApp{
    ofPoint ps[size];

public:
    void setup() {
        ofBackground(0, 0, 0);
        ofSetColor(255, 255, 255);
        ofSetLogLevel(OF_LOG_VERBOSE);
        ofSetVerticalSync(true);
        for(int i = 0; i < size; i++) {
            ps[i] = ofRandomScreenPoint();
        }
    }
    
    void update() {
        ps[size - 1] = ofRandomScreenPoint();
        for(int i = 0; i < size - 1; i++) {
            ps[i] = ofLerp(ps[i], ps[i + 1], 0.99f);
        }

    }
    
    void draw() {
        for(int i = 0; i < drawSize; i++) {
            ofLine(ps[i], ps[i + 1]);
        }
    }
};
