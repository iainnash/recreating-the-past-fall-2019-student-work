#include "ofPartialNatalieVera.hpp"

void ofPartialNatalieVera::draw1() {
    ofBackground(255);
    float lineSpacing = ofGetWidth()/100 ;
    
    for(int hor = 0; hor < 100; hor ++) { // draws horizontal lines
        ofSetColor(28, 48, 103);
        ofSetLineWidth(lineSpacing/2);
        ofDrawLine(0, hor * lineSpacing, ofGetWidth(), hor * lineSpacing);
    }
    
    
    for(int vert = 0; vert < 101; vert ++ ) { // draws vertical lines with an upperbound on the noise curve
        ofSetColor(28, 48, 103);
        ofSetLineWidth(lineSpacing/2);
        ofDrawLine(vert*lineSpacing, ofNoise(vert* 0.1 + 500)* 300, vert*lineSpacing, ofGetHeight());
        ofSetColor(255);
        ofDrawLine(vert*lineSpacing + lineSpacing/2, ofNoise(vert*0.1 + 500) * 300, vert*lineSpacing + lineSpacing/2, ofGetHeight()); // draws every other line in white to achieve painter's algo
        
    }
}


void ofPartialNatalieVera::draw2() {
    ofSeedRandom(0);
    float height = ofGetHeight() / 24;
    float width = ofGetWidth() / 16;
    
    for (int i = 0; i < width; i ++ ) {
        for (int j = 0; j < height; j ++ ) {
            
            
            ofNoFill();
            ofSetColor(94, 60, 70);
            ofDrawRectangle(i*width, j*height, 50, 50);
            
            if (ofNoise(i*0.5, j*0.5) > 0.1) {
                ofFill();
                ofSetColor(ofRandom(82, 155), ofRandom(30, 39), ofRandom(30, 48));
                ofDrawRectangle(i*width, j*height, 50, 50);

            }
            
            if (ofNoise(i* 0.5, j*0.5) > 0.3) {
                ofFill();
                ofSetColor(ofRandom(156, 208), ofRandom(40, 55), ofRandom(48, 75));
                ofDrawRectangle(i*width, j*height, 50, 50);
            }
            
            
            if (ofNoise(i*0.5, j*0.5) > 0.5) {
                ofFill();
                ofSetColor(ofRandom(208, 223), ofRandom(180, 187), ofRandom(190, 201));
                ofDrawRectangle(i*width, j*height, 50, 50);
            }
            
            if (ofNoise(i*0.5, j*0.5) > 0.9) {
                ofFill();
                ofSetColor(ofRandom(209, 212), ofRandom(99, 121), ofRandom(79, 92));
                ofDrawRectangle(i*width, j*height, 50, 50);
            }

            }
        
        }
}


void ofPartialNatalieVera::draw3() {
ofSeedRandom(0);
        float margin = 120;
        float width = (ofGetWidth() - (margin*2)) / 6;
        float height = (ofGetHeight() - (margin*2)) / 6;
        for (int i = 0; i < 6; i ++ ) {
            for (int j = 0; j < 6; j ++ )
            {
                // 90% of the time will draw a quadralateral
                    ofPushMatrix();
                    ofTranslate(i*width + margin + width / 2 , j*height + margin + height / 2);
    //                ofRotateDeg(ofRandom(-10, 10`));
                    ofPolyline quads;

               
                    quads.addVertex(-width / 2 + ofRandom(- width / 3, width / 6), ofRandom( - height / 3, height / 6));
                    quads.addVertex(width / 2 + ofRandom(- width / 3, width / 6), ofRandom(- height / 3, height / 6));
                    quads.addVertex(width / 2 + ofRandom(- width / 3, width / 6), height / 2 + ofRandom(- height / 3, height / 6));
                if (ofNoise(i * 0.1, j * 0.05) > 0.2) {
                    quads.addVertex(-width / 2 + ofRandom(-width / 3, width / 6), height / 2 + ofRandom(- height / 3, height / 6));
                }
                
                quads.close();
                quads.draw();
                ofPopMatrix();

                }
                
            }
}
