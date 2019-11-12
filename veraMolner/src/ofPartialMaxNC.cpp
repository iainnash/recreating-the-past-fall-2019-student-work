#include "ofPartialMaxNC.hpp"

void ofPartialMaxNC::draw() {
    ofBackground(255, 255, 255);
    ofSetColor(0, 0, 0);
    ofSeedRandom(0);
    //    DRAWING THE VERTICAL LINES
    for (int i = 0; i < 26; i++) {
        ofSetLineWidth(30 - i*2);
        ofDrawLine(i*40, 0, i*40, ofGetHeight());
    }
    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 26; j++){
            //      DRAWING THE HORIZONTAL LINES
            float posx = i + 2;
            float posy = ofMap(j, 0, 26, 0, ofGetHeight());
            float offset = ofGetHeight()/2 - 2. * (ofGetHeight()/2)  * ofSignedNoise(i * .002 * (float)mouseY/(float)ofGetHeight() + mouseX*0.1);
            if (posy < offset) {
                ofDrawCircle(posx, posy, ofMap(j, 0, 26, 10, 1));
            }
        }
    }
}

