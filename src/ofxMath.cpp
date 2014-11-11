//
//  ofxMath.cpp
//
//  Created by ISHII 2bit.
//
//

#include "ofxMath.h"

#pragma mark extend ofLerp

ofColor ofLerp(const ofColor &start, const ofColor &stop, float amt) {
    return ofColor(ofLerp(start.r, stop.r, amt),
                   ofLerp(start.g, stop.g, amt),
                   ofLerp(start.b, stop.b, amt),
                   ofLerp(start.a, stop.a, amt));
}

ofVec2f ofLerp(const ofVec2f &start, const ofVec2f &stop, float amt) {
    return start.getInterpolated(stop, amt);
}

ofVec3f ofLerp(const ofVec3f &start, const ofVec3f &stop, float amt) {
    return start.getInterpolated(stop, amt);
}

ofVec4f ofLerp(const ofVec4f &start, const ofVec4f &stop, float amt) {
    return start.getInterpolated(stop, amt);
}

ofRectangle ofLerp(const ofRectangle &start, const ofRectangle &stop, float amt) {
    return ofRectangle(start.position.getInterpolated(stop.position, amt),
                       ofLerp(start.width,  stop.width,  amt),
                       ofLerp(start.height, stop.height, amt));
}

#pragma mark extend ofRandom

ofPoint ofRandomScreenPoint() {
    return ofPoint(ofRandomWidth(), ofRandomHeight());
}

ofRectangle ofRandomScreenRectangle(float width = -1.0f, float height = -1.0f) {
    if(width < 0.0f) width = ofRandomWidth();
    if(height < 0.0f) height = ofRandomHeight();
    
    return ofRectangle(ofRandom(ofGetWidth() - width), ofRandom(ofGetHeight() - height), width, height);
}

ofColor ofRandomColor(bool isAlphaEnable, bool isGrayscale) {
    unsigned char r = ofRandom(256);
    unsigned char g = isGrayscale ? r : ofRandom(256);
    unsigned char b = isGrayscale ? r : ofRandom(256);
    unsigned char a = isAlphaEnable ? ofRandom(256) : 255;
    
    return ofColor(r, g, b, a);
}