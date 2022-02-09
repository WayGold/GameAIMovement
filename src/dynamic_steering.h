#pragma once
#include "ofMain.h"

class DynamicOutput {
public:
	glm::vec2 linearAccel;
	float rotAccel;

	DynamicOutput(glm::vec2 i_linearAccel, float i_rotAccel);
	~DynamicOutput();
};

struct DynamicSteeringOutput {
	glm::vec2 linearAccel;
	float rotAccel;
};