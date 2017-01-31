#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    buf.setSize(10);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<10;i++){
        ofDrawBitmapString(buf.getValue(i), 20+i*40, 40);
    }
    ofPushMatrix();
    ofTranslate(20+buf.getCurPos()*40, 50);
    ofSetColor(ofColor::red);
    ofDrawLine(-10, 0, 10, 0);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    buf.posUp();
    for(int i=0;i<buf.getSize();i++){
        ofxCircularBuffer<int>::BufferIterator it = buf.nthFromBegin(i);
        *it +=1;
    }
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
