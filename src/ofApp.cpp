#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){
	states.push_back("SEEKER");
	states.push_back("TARGET");
	states.push_back("FOLLOWER");
	states.push_back("WANDERER");
	states.push_back("LEADER");
	currentState = states.begin();
}

//--------------------------------------------------------------
void ofApp::update(){
	auto deltaTime = ofGetLastFrameTime();

	std::stringstream strm;
	strm << "fps: " << trunc(ofGetFrameRate()) << ", OnClick Create: " << (*currentState);
	ofSetWindowTitle(strm.str());



	for (auto it = allSeekers.begin(); it != allBoids.end(); ++it) {
		(*it)->boidRB->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (auto it = allBoids.begin(); it != allBoids.end(); ++it) {
		(*it)->draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_DOWN) {
		if ((++currentState) != states.end()) {
		}
		else {
			currentState = states.begin();
		}
	}

	if (key == OF_KEY_UP) {
		if ((currentState) == states.begin()) {
			currentState += states.size() - 1;
		}
		else {
			currentState--;
		}
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
	Boid* newBoid = new Boid(glm::vec2(x, y), 20, 10, ofColor(255, 0, 0));
	allBoids.push_back(newBoid);
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
