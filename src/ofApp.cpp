#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup() {

	// Init States
	states.push_back("SEEKER");
	states.push_back("TARGET");
	states.push_back("FOLLOWER");
	states.push_back("WANDERER");
	states.push_back("LEADER");

	// Set Initial State to Seeker
	currentState = states.begin();

	// Init Movement Algorithms
	dynamicSeek = new DynamicSeek(nullptr, nullptr, maxAcceleration);
	dynamicFace = new DynamicFace(nullptr, nullptr, maxAngularAcceleration, maxRotation, targetRadius, slowRadius);
	dynamicLWYG = new DynamicLookWhereYouAreGoing(nullptr, maxAngularAcceleration, maxRotation, targetRadiusRot, slowRadiusRot);
	dynamicWander = new DynamicWander(nullptr, glm::pi<float>(), glm::pi<float>() / 4, maxAcceleration, targetRadiusRot,
		slowRadiusRot, wanderOffset, wanderRate);
}

//--------------------------------------------------------------
void ofApp::update() {
	auto deltaTime = ofGetLastFrameTime();

	std::stringstream strm;
	strm << "fps: " << trunc(ofGetFrameRate()) << ", OnClick Create: " << (*currentState);
	ofSetWindowTitle(strm.str());

	if (allSeekers.size() != 0 && seekTarget) {
		// Get steering and update all
		for (auto it = allSeekers.begin(); it != allSeekers.end(); ++it) {
			// Set up input to algorithms
			dynamicSeek->characterRB = (*it)->boidRB;
			dynamicSeek->targetRB = seekTarget->boidRB;
			/*dynamicFace->characterRB = (*it)->boidRB;
			dynamicFace->targetRB = seekTarget->boidRB;*/
			dynamicLWYG->characterRB = (*it)->boidRB;
			// Get steering - seek + face/LWYG
			auto steeringOutput = dynamicSeek->getSteering();
			//steeringOutput.rotAccel = dynamicFace->getSteering().rotAccel;
			steeringOutput.rotAccel = dynamicLWYG->getSteering().rotAccel;
			(*it)->boidRB->update(steeringOutput, maxSpeed, deltaTime);
		}
	}

	if (allWanderers.size() != 0) {
		for (auto it = allWanderers.begin(); it != allWanderers.end(); ++it) {
			dynamicWander->characterRB = (*it)->boidRB;
			// Switch wander style by passing in true/false
			auto steeringOutput = dynamicWander->getSteering(false);
			(*it)->boidRB->update(steeringOutput, maxSpeed, deltaTime);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (auto it = allBoids.begin(); it != allBoids.end(); ++it) {
		(*it)->draw();
	}
}

void ofApp::exit()
{
	if (dynamicSeek)
		delete dynamicSeek;

	if (dynamicFace)
		delete dynamicFace;

	if (dynamicWander)
		delete dynamicWander;

	if (dynamicLWYG)
		delete dynamicLWYG;

	if (allBoids.size() != 0) {
		for (auto it = allBoids.begin(); it != allBoids.end(); ++it) {
			delete* it;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
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
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	if (*currentState == "SEEKER") {
		allSeekers.push_back(new Boid(glm::vec2(x, y), 20, 10, ofColor(255, 0, 0)));
		allBoids.push_back(allSeekers.back());
	}

	if (*currentState == "TARGET") {
		if (seekTarget) {
			allBoids.erase(allBoids.begin() + seekTargetIndex);
			seekTargetIndex = -1;
			delete seekTarget;
		}
		seekTarget = new Boid(glm::vec2(x, y), 20, 10, ofColor(0, 255, 255));
		seekTargetIndex = allBoids.size();
		allBoids.push_back(seekTarget);
	}

	if (*currentState == "FOLLOWER") {
		allFollowers.push_back(new Boid(glm::vec2(x, y), 20, 10, ofColor(153, 255, 153)));
		allBoids.push_back(allFollowers.back());
	}

	if (*currentState == "WANDERER") {
		allWanderers.push_back(new Boid(glm::vec2(x, y), 20, 10, ofColor(255, 204, 229)));
		allBoids.push_back(allWanderers.back());
	}

	if (*currentState == "LEADER") {
		allLeaders.push_back(new Boid(glm::vec2(x, y), 20, 10, ofColor(255, 255, 0)));
		allBoids.push_back(allLeaders.back());
	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
