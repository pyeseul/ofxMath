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

ofColor ofLerp(const ofColor &start, const ofColor &stop, float amt);

ofVec2f ofLerp(const ofVec2f &start, const ofVec2f &stop, float amt);
ofVec3f ofLerp(const ofVec3f &start, const ofVec3f &stop, float amt);
ofVec4f ofLerp(const ofVec4f &start, const ofVec4f &stop, float amt);

ofRectangle ofLerp(const ofRectangle &start, const ofRectangle &stop, float amt);

#pragma mark extend ofRandom

ofPoint ofRandomScreenPoint();
ofRectangle ofRandomScreenRectangle();
ofColor ofRandomColor(bool isAlphaEnable = false, bool isGrayscale = false);

#endif /* defined(__ofxMath__) */
