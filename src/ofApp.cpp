#include "ofApp.h"

ofApp::ofApp() : particleSys(ofVec3f(0, 0, 0)){

}

//--------------------------------------------------------------
void ofApp::setup() {
    angle = 0;
    
    ofEnableDepthTest();
    ofSetVerticalSync(true);
    
    cam.setDistance(160);
    particleSys.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    cam.begin();
    ofPushMatrix();
            //Rotating as the camera rotates this keeps the black ellipse drawn seem statically place within the background whilst the sketch burns away in the foreground
            //rotateX(camera[0]);
            //rotateY(camera[1]);
            //This sets the ellipse -600 in the z axis
            ofTranslate(0, 0, 0);
    
        //I found out about use of pushStles from a friend and realise that this helps to style a specific shape without affecting other parts of the sketch
        //similar to pushMatirx();
        ofPushStyle();
            ofSetColor(0, 0, 0, 0.5);
            ofFill();
            ofDrawEllipse(0, 0, ofGetWidth()/10, ofGetHeight()/10);
        ofPopStyle();
    ofPopMatrix();
    
    particleSys.addParticles();
    particleSys.run();
    
    cam.end();

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
