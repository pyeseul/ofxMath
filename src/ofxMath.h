//
//  ofxMath.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxMath__
#define __ofxMath__

#include "ofMain.h"

#pragma mark extend ofLerp

inline ofColor ofLerp(const ofColor &start, const ofColor &stop, float amt) {
    return ofColor(ofLerp(start.r, stop.r, amt),
                   ofLerp(start.g, stop.g, amt),
                   ofLerp(start.b, stop.b, amt),
                   ofLerp(start.a, stop.a, amt));
}

inline ofVec2f ofLerp(const ofVec2f &start, const ofVec2f &stop, float amt) {
    return start.getInterpolated(stop, amt);
}

inline ofVec3f ofLerp(const ofVec3f &start, const ofVec3f &stop, float amt) {
    return start.getInterpolated(stop, amt);
}

inline ofVec4f ofLerp(const ofVec4f &start, const ofVec4f &stop, float amt) {
    return start.getInterpolated(stop, amt);
}

inline ofRectangle ofLerp(const ofRectangle &start, const ofRectangle &stop, float amt) {
    return ofRectangle(start.position.getInterpolated(stop.position, amt),
                       ofLerp(start.width,  stop.width,  amt),
                       ofLerp(start.height, stop.height, amt));
}

#pragma mark extend ofRandom

inline ofPoint ofRandomScreenPoint(float margin = 0.0f) {
    return ofPoint(ofRandom(ofGetWidth() - 2 * margin) + margin, ofRandom(ofRandomHeight() - 2 * margin) + margin);
}

inline ofRectangle ofRandomScreenRectangle(float width = ofRandomWidth(), float height = ofRandomHeight()) {
    return ofRectangle(ofRandom(ofGetWidth() - width), ofRandom(ofGetHeight() - height), width, height);
}

inline ofColor ofRandomColor(bool isAlphaEnable, bool isGrayscale) {
    unsigned char r = ofRandom(256);
    unsigned char g = isGrayscale ? r : ofRandom(256);
    unsigned char b = isGrayscale ? r : ofRandom(256);
    unsigned char a = isAlphaEnable ? ofRandom(256) : 255;
    
    return ofColor(r, g, b, a);
}

#pragma mark about ofPoint, ofVecNf

inline ofVec2f ofRandomVec2f(float min = -1.0f, float max = 1.0f) {
    return ofVec2f(ofRandom(min, max), ofRandom(min, max));
}

inline ofVec3f ofRandomVec3f(float min = -1.0f, float max = 1.0f) {
    return ofVec3f(ofRandom(min, max), ofRandom(min, max), ofRandom(min, max));
}

inline ofVec4f ofRandomVec4f(float min = -1.0f, float max = 1.0f) {
    return ofVec4f(ofRandom(min, max), ofRandom(min, max), ofRandom(min, max), ofRandom(min, max));
}

inline ofPoint ofRandomPointf(float min = -1.0f, float max = 1.0f) {
    return ofRandomVec3f(min, max);
}

#pragma mark about rectangle

inline ofRectangle ofxAspectFittedRectangle(float width, float height, const ofRectangle &rect) {
    ofRectangle result;
    if(width / height < rect.width / rect.height) {
        float scale = rect.width / width;
        result.width = rect.width;
        result.height = height * scale;
        result.x = rect.x;
        result.y = rect.y + (rect.height - result.height) * 0.5f;
    } else {
        float scale = rect.height / height;
        result.width = width * scale;
        result.height = rect.height;
        result.x = rect.x + (rect.width - result.width) * 0.5f;
        result.y = rect.y;
    }
    return result;
}

inline ofRectangle ofxAspectFilledRectangle(float width, float height, const ofRectangle &rect) {
    ofRectangle result;
    if(width / height < rect.width / rect.height) {
        float scale = rect.height / height;
        result.width = width * scale;
        result.height = rect.height;
        result.x = rect.x + (rect.width - result.width) * 0.5f;
        result.y = rect.y;
    } else {
        float scale = rect.width / width;
        result.width = rect.width;
        result.height = height * scale;
        result.x = rect.x;
        result.y = rect.y + (rect.height - result.height) * 0.5f;
    }
    return result;
}

#endif /* defined(__ofxMath__) */
