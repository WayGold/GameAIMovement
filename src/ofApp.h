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
		std::vector<Boid*> allWanderers;
		std::vector<Boid*> allFollowers;
		std::vector<Boid*> allLeaders;

		Boid* seekTarget = nullptr;
		float seekTargetIndex = -1;

		std::vector<string> states;
		std::vector<string>::iterator currentState;

		DynamicSeek* dynamicSeek = nullptr;
		DynamicFace* dynamicFace = nullptr;
		DynamicWander* dynamicWander = nullptr;
		DynamicLookWhereYouAreGoing* dynamicLWYG = nullptr;
		
		const float maxSpeed = 100;
		const float maxAcceleration = 50;

		const float slowRadius = 50;
		const float targetRadius = 2;

		const float maxRotation =  10 * glm::pi<float>();
		const float maxAngularAcceleration = 2 * glm::pi<float>();

		const float slowRadiusRot = glm::pi<float>() / 4;
		const float targetRadiusRot = glm::pi<float>() / 64;

		const float wanderOffset = 5;
		const float wanderRate = glm::pi<float>() / 8;
		
		void setup();
		void update();
		void draw();
		void exit();

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
