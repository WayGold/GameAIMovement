#pragma once

#include "ofMain.h"
#include <vector>
#include "aiService.h"
#include <unordered_map>
#include <string>

class ofApp : public ofBaseApp{

	public:
		std::vector<Boid*> allBoids;
		std::vector<Boid*> allSeekers;
		std::vector<Boid*> allWanders;
		std::vector<Boid*> allFollowers;
		std::vector<Boid*> allLeaders;

		Boid* seekTarget;

		std::vector<string> states;
		std::vector<string>::iterator currentState;

		const float maxSpeed = 10;
		const float maxAcceleration = 5;
		const float maxRotation = glm::pi<float>() / 8;
		const float maxAngularAcceleration = glm::pi<float>() / 16;
		const float slowRadius = 100;
		const float targetRadius = 15;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
