#include "ofPartialYuzhu.hpp"

void ofPartialYuzhu::draw() {
    ofSetColor(ofColor(200,55,0));
    ofSeedRandom(218 * 1000);
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 16; j++) {
            float x = ofMap(i, 0, 14, 20, 580);
            float y = ofMap(j, 0, 16, 20, 580);
            ofNoFill();
            //          the range of each line's is x, x + 45, y, y +45
            //          ofDrawRectangle(x, y, 45, 45);
            float x1 = ofRandom(x, x + 50);
            float y1 = ofRandom(y, y + 50);
            
            for (int k = 0; k < 18; k++){
                float x2 = ofRandom(x, x + 38);
                float y2 = ofRandom(y, y + 33);
                ofDrawLine(x1, y1, x2, y2);
                x1 = x2;
                y1 = y2;
            }
        }
    }
}
