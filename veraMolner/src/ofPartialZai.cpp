#include "ofPartialZai.hpp"

void ofPartialZai::setup() {
    width = 50;
    for (int j = 0; j < 1252; j++) {
        float roundedAngle = ofRandom(20, 45);
        rounded.push_back(roundedAngle);
    }
}

void ofPartialZai::draw() {
    ofSeedRandom(mouseX * 1000);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofBackground(255);
    ofSetColor(30);
    float thickness;
    float height;
    float distanceFrom;
    
    ofPushMatrix();
    ofTranslate(50, 125);
    
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width/2; j++) {
            
            //            calculatee distance from mouse
            float distance = abs(mouseX - (50 + i*20));
            
            //            divide input by evenizer variable of ~2 when mouse is in center of screen
            float evenizer = ofMap(distance, 0, ofGetWidth() - 100, 2.3, 1);
            
            //            make angle crazier when closer to mouse
            float crazyAngle = ofMap(distance, 0, (ofGetWidth() - 100)/evenizer, 20, 0);
            
            //            width of rect based on distance from mouse, thicker when closer to black hole
            distanceFrom = ofMap(distance, 0, (ofGetWidth() - 100)/evenizer, 15, 1);
            
            //            make height of rect longer when in black hole
            float height = ofMap(distance, 0, (ofGetWidth() - 100)/evenizer, 50, 25);
            ofPushMatrix();
            
            ofTranslate(i*20, j*20 - 25);
            ofRotateDeg(ofRandom(20, 45 + crazyAngle));
            ofDrawRectRounded(0, 0, distanceFrom, height, 25);
            
            ofPopMatrix();
            
        }
    }
    
    ofPopMatrix();
    
}
