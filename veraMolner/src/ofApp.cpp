#include "ofApp.h"
#include "ofPartialNatalieVera.hpp"
#include "ofPartialFrojoVera.hpp"
#include "ofPartialMathildemouwVera.hpp"
#include "ofPartialMaxBittkerVera.hpp"
#include "ofPartialShelbyVera.hpp"
#include "ofPartialKatherine.hpp"
#include "ofPartialMaxNC.hpp"
#include "ofPartialZai.hpp"
#include "ofPartialYuzhu.hpp"

class Person {
public:
    string name;
    vector<std::function<void()>> drawFns;
    vector<string> drawText;
    
    Person(string name) : name(name) {
        // no-op
    }
    
};

vector<Person> people;


//--------------------------------------------------------------
void ofApp::setup(){
    font.load("Trattatello.ttf", 40);
    
    Person p1("Natalie");
    ofPartialNatalieVera partialNatalie;
    partialNatalie.setup();
    p1.drawFns.push_back([&] { partialNatalie.draw1(); });
    p1.drawText.push_back("Draw 1");
    p1.drawFns.push_back([&] { partialNatalie.draw2(); });
    p1.drawText.push_back("Draw 2");
    p1.drawFns.push_back([&] { partialNatalie.draw3(); });
    p1.drawText.push_back("Draw 3");
    people.push_back(p1);
    
    Person p2("Frojo");
    ofPartialFrojoVera partialFrojo;
    partialFrojo.setup();
    p2.drawFns.push_back([&] { partialFrojo.draw1(); });
    p2.drawText.push_back("Draw 1");
    p2.drawFns.push_back([&] { partialFrojo.draw2(); });
    p2.drawText.push_back("Draw 2");
    p2.drawFns.push_back([&] { partialFrojo.draw3(); });
    p2.drawText.push_back("Draw 3");
    p2.drawFns.push_back([&] { partialFrojo.draw4(); });
    p2.drawText.push_back("Draw 4");
    people.push_back(p2);
    
    
    Person p3("Iain");
    ofPartialFrojoVera partialIain;
    partialIain.setup();
    p3.drawFns.push_back([&] { partialIain.draw1(); });
    p3.drawText.push_back("Draw 1");
    p3.drawFns.push_back([&] { partialIain.draw2(); });
    p3.drawText.push_back("Draw 2");
    p3.drawFns.push_back([&] { partialIain.draw3(); });
    p3.drawText.push_back("Draw 3");
    p3.drawFns.push_back([&] { partialIain.draw4(); });
    p3.drawText.push_back("Draw 4");
    people.push_back(p3);
    
    Person p4("Mathilde");
    ofPartialFrojoVera partialMathilde;
    partialMathilde.setup();
    p4.drawFns.push_back([&] { partialMathilde.draw(); });
    p4.drawText.push_back("Draw");
    people.push_back(p4);
    
    Person p5("Shelby");
    ofPartialShelbyVera partialShelby;
    partialShelby.setup();
    p5.drawFns.push_back([&] { partialShelby.carresNoir(); });
    p5.drawText.push_back("carresNoir");
    p5.drawFns.push_back([&] { partialShelby.shallWeTakeAWalk(); });
    p5.drawText.push_back("shallWeTakeAWalk");
    p5.drawFns.push_back([&] { partialShelby.untitled6Y1972(); });
    p5.drawText.push_back("untitled6Y1972");
    p5.drawFns.push_back([&] { partialShelby.grisSurArgent(); });
    p5.drawText.push_back("grisSurArgent");
    p5.drawFns.push_back([&] { partialShelby.dispersesParLeVentAuLarge(); });
    p5.drawText.push_back("dispersesParLeVentAuLarge");
    p5.drawFns.push_back([&] { partialShelby.hommageADurer(); });
    p5.drawText.push_back("hommageADurer");
    p5.drawFns.push_back([&] { partialShelby.hommageADurer1990(); });
    p5.drawText.push_back("hommageADurer1990");
    people.push_back(p5);
    
    // to add: katherine
    Person p6("Katherine");
    ofPartialKatherine partialKatherine;
    partialKatherine.setup();
    p6.drawFns.push_back([&] { partialKatherine.draw() });
    p6.drawText.push_back("draw");
    
    Person p7("Max NC");
    ofPartialMaxNC partialMaxNC;
    partialMaxNC.setup();
    p7.drawFns.push_back([&] { partialMaxNC.draw() });
    p7.drawText.push_back("draw");
    
    Person p8("Zai");
    ofPartialZai partialZai;
    partialZai.setup();
    p8.drawFns.push_back([&] { partialZai.draw() });
    p8.drawText.push_back("draw");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

int selectedPerson = 0;
int selectedSketch = 0;
bool isDrawing = false;
//--------------------------------------------------------------
void ofApp::draw(){
    if (isDrawing) {
        people[selectedPerson].drawFns[selectedSketch]();
    } else {
        
        ofBackground(255);
        ofSetColor(0);
        int count = 0;
        for (auto person : people) {
            count += 1;
            font.drawString(person.name, 20, count * 50);
            ofDrawRectangle(20, count * 50, 300, 5);
        }
        int txtCount = 0;
        for (auto sketch : people[selectedPerson].drawText) {
            txtCount += 1;
            font.drawString(sketch, ofGetWidth() / 2, txtCount * 50);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_UP) {
        if (selectedPerson - 1 >= 0) {
            selectedPerson -= 1;
            selectedSketch = 0;
        }
    }
    if (key == OF_KEY_DOWN) {
        if (selectedPerson + 1 < people.size()) {
            selectedPerson += 1;
            selectedSketch = 0;
        }
    }
    if (key == 'N' || key == 'n') {
        if (selectedSketch + 1 < people[selectedPerson].drawFns.size()) {
            selectedSketch += 1;
        }
    }
    if (key == 'P' || key == 'p') {
        if (selectedSketch - 1 >= 0) {
            selectedSketch -= 1;
        }
    }
    if (key == OF_KEY_RETURN) {
        isDrawing = !isDrawing;
    }
    cout << "selected person: " << selectedPerson << ", selectedSketch: " << selectedSketch << endl;
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
