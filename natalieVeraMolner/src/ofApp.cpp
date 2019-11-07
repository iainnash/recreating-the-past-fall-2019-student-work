#include "ofApp.h"

void ofDrawLineCompat(float lineWidth, float startX, float endX, float startY, float endY) {
    ofPushMatrix();
    float deltaX = endX - startX;
    float deltaY = endY - startY;
    float width = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    
    ofTranslate(width / 2, lineWidth / 2);
    
    float rotateBy = -atan2(deltaY, deltaX);
    ofRotateRad(rotateBy);
    
    ofDrawRectangle(0, 0, width, lineWidth);
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    
//    ofSetColor(0, 255, 0);
//    ofDrawLineCompat(20, 100, 100, 400, 100);
//    ofSetColor(0, 0, 255);
//    ofDrawLineCompat(10, 100, 100, 100, 400);
    
    
    ofSetColor(255, 0, 0);
//    ofDrawLine(50, 50, 200, 200);
    ofDrawLineCompat(10, 50, 50, 200, 200);
    /*
    float lineSpacing = ofGetWidth()/100 ;
    
    for(int hor = 0; hor < 100; hor ++) { // draws horizontal lines
        ofSetColor(28, 48, 103);
        ofSetLineWidth(lineSpacing/2);
        ofDrawLine(0, hor * lineSpacing, ofGetWidth(), hor * lineSpacing);
    }
    
    
    for(int vert = 0; vert < 101; vert ++ ) { // draws vertical lines with an upperbound on the noise curve
        ofSetColor(28, 48, 103);
        ofSetLineWidth(lineSpacing/2);
        ofSetColor(28, 48, 103, 0.3);
        ofDrawLineCompat(lineSpacing / 2, vert*lineSpacing, ofNoise(vert* 0.1 + 500)* 300, vert*lineSpacing, ofGetHeight());
        ofSetColor(255);
        ofSetColor(90,0,100);
        ofDrawLineCompat(lineSpacing / 2, vert*lineSpacing + lineSpacing/2, ofNoise(vert*0.1 + 500) * 300, vert*lineSpacing + lineSpacing/2, ofGetHeight()); // draws every other line in white to achieve painter's algo
        
    }
     */
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
