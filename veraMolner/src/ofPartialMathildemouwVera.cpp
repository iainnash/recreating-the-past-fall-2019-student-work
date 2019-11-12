#include "ofPartialMathildemouwVera.hpp"

void ofPartialMathildemouwVera::draw() {
    float i;
    float newi;
    float offsetFromBottom  = 450;
    float marginLeft = 50;
    
    // playing with noise and randomness
    // considerations:
    
    // max min lengths of Vera Molnár's angled lines
    // also frequency of them
    // also overlappingness, cluster them together more by using Noise instead of Random
    
    // min max length of interruptions
    // frequency of interruptions
    
    ofSeedRandom(mouseX);
    // 67
    ofSetColor(0);
    
    for (i =  0; i < 20; i ++) {
        newi = ofMap(i, 0, 20, 0, ofGetScreenHeight() - offsetFromBottom);
        ofDrawLine(
                   // vary where the horizonatal line starts
                   (ofNoise(i * 0.9) * 200.0) + marginLeft,
                   newi + 200,
                   // draw lines all to be about the same length
                   ((ofNoise(i * 0.9) * 200.0) + marginLeft) + (ofGetScreenWidth() / 3) + ofRandom(20),
                   newi + 200);
    }
    
    //
    // second layer: INTERRUPTIONS
    //
    
    ofSeedRandom(mouseX);
    // 400 * 20
    ofSetColor(255);
    
    for (i =  0; i < 20; i ++) {
        newi = ofMap(i, 0, 20, 0, ofGetScreenHeight() - offsetFromBottom);
        ofDrawRectangle(ofRandom(ofGetScreenWidth() * 2), newi + 197 , ofRandom(20), 20);
    }
    
    //
    // last layer: SHORT ANGLED LINES
    //
    
    ofSetColor(0);
    ofSeedRandom(mouseX);
    cout  <<  mouseX << endl;
    // 326 is a  pretty good one
    
    for (i =  0; i < 20; i ++) {
        newi = ofMap(i, 0, 20, 0, ofGetScreenHeight() - offsetFromBottom);
        
        // centerX controls where on the horizontal it lands
        float centerX = (ofNoise(i * 0.9) * 937);//2000.0);
        float centerY = newi + 200;
        // angle of line is mostly controlled by slopeY
        float slopeY = ofRandom(25) + 5;
        // length of line is mostly controlled by slopeX
        float slopeX = ofRandom(40) + 5;
        
        float j;
        for (j =  0; j < ofRandom(5); j ++) {
            ofDrawLine(centerX + slopeX, centerY - slopeY, centerX, centerY);
            ofDrawLine(centerX, centerY, centerX - slopeX, centerY + slopeY);
        };
    };
}
