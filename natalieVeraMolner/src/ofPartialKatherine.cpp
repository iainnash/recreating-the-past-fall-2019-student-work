#include "ofPartialKatherine.hpp"

void ofPartialKatherine::draw() {
    ofBackground(225);
    ofSetColor(0, 0, 0);
    
    ofSeedRandom(ofGetMouseX()*1000);
    
    int marginLeft = ofGetWidth()/5;
    
    
    for (int i = 0; i < 20; i++) {          // number of rows
    
        int y = (ofGetHeight()/5) + i*20;   // for scaling change step size


        
        for (int j = 0; j < 20; j++) {      // number of lines in one row
            
            int x = marginLeft + j*20;
            
            ofPushMatrix();
            ofTranslate(x, y);
            
            float randomNumber = ofRandom(1);
            
            if (randomNumber < 0.9) {       // draw straight line
                
                ofDrawLine(0 - ofRandom(10), 0, 0 + ofRandom(10), 0);

            }
            
            
            if (randomNumber > .9) {        // 10% of the time draw angled line
            
                ofRotateDeg(ofRandom(-45, 0));
                ofDrawLine(0 - ofRandom(70), 0, 0 + ofRandom(70), 0);
                cout << randomNumber << endl;
            }
            ofPopMatrix();
        }
        
        
    }
}
