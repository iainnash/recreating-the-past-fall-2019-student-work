//
//  ofPartialIainVera.cpp
//  natalieVeraMolner
//
//  Created by iain nash on 11/8/19.
//

#include "ofPartialIainVera.hpp"


void drawLineAtAngle(int elWidth, int x, int y, int angle) {
    ofPushMatrix();
    ofTranslate(x + elWidth / 2, y + elWidth / 2);
    ofRotateZDeg(angle * 45);
    ofDrawLine(-1 * elWidth / 3, 0, elWidth / 3, 0);
    ofPopMatrix();
}

void ofPartialIainVera::draw1() {
    ofBackground(55);
    ofSetColor(158);
    ofNoFill();
    
    const int gridSize = 3;
    
    int startAt = ofGetWidth() * 0.4 / 4.0;
    int endAt = ofGetWidth() * 3.4 / 4.0;
    int elWidth = (endAt - startAt) / gridSize;

    for (int j = 0; j < gridSize; j++) {
        int angleAmounts = 2;
        for (int i = 0; i < gridSize; i++) {
            int x = ofMap(i, 0, gridSize, startAt, endAt);
            int y = ofMap(j, 0, gridSize, startAt, endAt);
            ofDrawRectangle(x, y, elWidth, elWidth);

            int atSquare = i + j * gridSize;
            if (atSquare < 4) {
                drawLineAtAngle(elWidth, x, y, (2 + atSquare) * 45);
            }
            if (atSquare > 4) {
                drawLineAtAngle(elWidth, x, y, (10 - atSquare) * 45);
            }
            if (atSquare == 4) {
                drawLineAtAngle(elWidth, x, y, 1 * 45);
                drawLineAtAngle(elWidth, x, y, 3 * 45);
            }
        }
    }
}

const int margin = 40;
const float chance_change = 0.88;
const float size_div = 3;

void ofPartialIainVera::draw2() {
    ofPolyline lines;
    ofNoFill();
    ofBackground(228);
    ofSetColor(82);
    
    int screenWidth = ofGetWidth();
    ofSeedRandom(mouseX * 4000);
    float accepted_deviation = ofMap(mouseY, 0, ofGetHeight(), 0, 20);
    
    int startAt = screenWidth - margin;
    for (int ox = startAt / 2; ox > margin; ox -= 10) {
        lines.clear();
        int size = screenWidth - ox * 2;
        lines.addVertex(ox, ox);
        if (ofRandom(1.f) > chance_change) {
            float atY = ox;
            int incr = ofRandom(size/size_div);
            while (atY < ox + size - 40) {
                lines.addVertex(ox + ofRandom(-1 * accepted_deviation, accepted_deviation), atY);
                atY += incr;
                incr = ofRandom(size/size_div*2);
            }
        }
        
        
        lines.addVertex(ox, ox + size);
        if (ofRandom(1.f) > chance_change) {
            float atX = ox;
            int incr = ofRandom(size);
            while (atX < ox + size - 40) {
                lines.addVertex(atX, ox + size + ofRandom(-1 * accepted_deviation, accepted_deviation));
                atX += incr;
                incr = ofRandom(size/size_div*2);
            }
        }
        
        
        lines.addVertex(ox + size, ox + size);
        if (ofRandom(1.f) > chance_change) {
            float atY = ox + size;
            int incr = ofRandom(size);
            while (atY > ox + 40) {
                lines.addVertex(ox + size + ofRandom(-1 * accepted_deviation, accepted_deviation), atY);
                atY -= incr;
                incr = ofRandom(size/size_div*2);
            }
        }
        
        
        lines.addVertex(ox + size, ox);
        if (ofRandom(1.f) > chance_change) {
            float atX = ox + size;
            int incr = ofRandom(size);
            while (atX > ox + 40) {
                lines.addVertex(atX, ox + ofRandom(-1 * accepted_deviation, accepted_deviation));
                atX -= incr;
                incr = ofRandom(size/size_div*2);
            }
        }
        lines.addVertex(ox, ox);
        lines.close();
        lines.draw();
        lines.clear();
    }
}


const int squareOffset = 50;
const int gridSize = 6;
const int offset = 10;
// This emulates "marker" colors in a plotter (6).
ofColor colors[] = {
    ofColor(144, 35, 41),    // red
    ofColor(139, 89, 158),   // purple
    ofColor(125, 114, 148),  // cyan dark
    ofColor(105, 161, 210),  // cyan
    ofColor(208, 240, 255),  // whiteish
    ofColor(238, 222, 15),   // yellow
};
const int colorsSize = 6;

int randomDivision = 4;
#define randoff ofRandom(-1 * squareEach * randomAmount, squareEach * randomAmount)
void setNewColor() {
    ofColor color = colors[(int)ofRandom(colorsSize)];
    color.setSaturation(220);
    color.setBrightness(180);
    ofSetColor(color.r, color.g, color.b, 200);
}

void ofPartialIainVera::draw3() {
    ofPolyline line;
    ofBackground(255);
    ofNoFill();
    ofSeedRandom(mouseX * 3000);
    ofEnableAlphaBlending();
    
    int squareFinal = ofGetWidth() - 300 - squareOffset;
    int squareEach = (squareFinal - squareOffset) / gridSize;
    ofSetLineWidth(1.5);
    for (int x = squareOffset, xi = 0; x < squareFinal; x += squareEach, xi++) {
        for (int y = squareOffset; y < squareFinal; y += squareEach) {
            float randomAmount = xi / 10.0 + (xi * xi / 28);
            if (xi == 1) {
                randomAmount = 0.03;
            }
            float positionOffsetX = xi > 3 ? ofRandom(-15, 55) : 0;
            setNewColor();
            for (int k = 0, kMax = (xi * 4) + 1; k < kMax; k++) {
                if (k % 3 == 0) {
                    setNewColor();
                }
                line.addVertex( // top left
                   x + offset + randoff + positionOffsetX,
                   y + offset + randoff
                );
                line.addVertex( // top right
                    x - offset + squareEach + randoff + positionOffsetX,
                    y + offset + randoff
                );
                line.addVertex( // bottom right
                    x - offset + squareEach + randoff + positionOffsetX,
                    y - offset + squareEach + randoff
                );
                line.addVertex( // bottom left
                    x + offset + randoff + positionOffsetX,
                    y - offset + squareEach + randoff
                );
                line.close();
                line.draw();
                line.clear();
            }
        }
    }
}


#define randoff2 ofRandom(-1 * squareEach / randomDivision, squareEach / randomDivision)
void ofPartialIainVera::draw4() {
    ofPolyline line;
    ofBackground(0);
    ofNoFill();
    ofSeedRandom(mouseX * 3000);
    ofEnableAlphaBlending();
    
    int squareFinal = ofGetWidth() - squareOffset;
    int squareEach = (squareFinal - squareOffset) / gridSize;
    ofSetLineWidth(4);
    for (int x = squareOffset; x < squareFinal; x += squareEach) {
        for (int y = squareOffset; y < squareFinal; y += squareEach) {
            ofColor color = colors[(int)ofRandom(colorsSize)];
            color.setBrightness(255);
            ofSetColor(color.r, color.g, color.b, 200);
            
            for (int k = 0, kMax = 8; k < kMax; k++) {
                line.addVertex( // top left
                   x + offset + randoff2,
                   y + offset + randoff2
                );
                line.addVertex( // top right
                    x - offset + squareEach + randoff2,
                    y + offset + randoff2
                );
                line.addVertex( // bottom right
                    x - offset + squareEach + randoff2,
                    y - offset + squareEach + randoff2
                );
                line.addVertex( // bottom left
                    x + offset + randoff2,
                    y - offset + squareEach + randoff2
                );
                line.close();
                line.draw();
                line.clear();
            }
        }
    }
}
