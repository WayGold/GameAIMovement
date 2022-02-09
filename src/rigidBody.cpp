#include "rigidBody.h"

RigidBody::RigidBody()
{
	this->position = glm::vec2(0.0f, 0.0f);
	this->orientation = 0.0f;
	this->velocity = glm::vec2(0.0f, 0.0f);
	this->rotVelocity = 0;
}

RigidBody::~RigidBody()
{
}

void RigidBody::update(DynamicSteeringOutput i_steering, float i_maxSpeed, float i_time)
{
	// Update the position and orientation.
	position += velocity * i_time;
	orientation += rotVelocity * i_time;

	// Update velocity and rotation.
	velocity += i_steering.linearAccel * i_time;
	rotVelocity += i_steering.rotAccel * i_time;

	// Check for speeding and clip.
	if (velocity.length() > i_maxSpeed){
		glm::normalize(velocity);
		velocity *= i_maxSpeed;
	}
}
