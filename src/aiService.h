#pragma once
#include "ofMain.h"
#include "rigidBody.h"

// Movement Output Data Types
namespace MovementOutputs {
	struct KinematicSteeringOutput {
		glm::vec2 linearVelocity;
		float rotVelocity;
	};
	struct DynamicSteeringOutput {
		glm::vec2 linearAccel;
		float rotAccel;
	};
}

MovementOutputs::KinematicSteeringOutput kinematic_seek(RigidBody characterRB, RigidBody targetRB, float maxSpeed);
MovementOutputs::KinematicSteeringOutput kinematic_flee(RigidBody characterRB, RigidBody targetRB, float maxSpeed);

MovementOutputs::DynamicSteeringOutput dynamic_seek(RigidBody characterRB, RigidBody targetRB, float maxLinearAccel);
MovementOutputs::DynamicSteeringOutput dynamic_arrive(RigidBody characterRB, RigidBody targetRB,
	float maxLinearAccel, float maxSpeed,
	float slowRadius, float targetRadius, float timeToTarget);
