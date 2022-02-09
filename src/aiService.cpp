#include "aiService.h"

MovementOutputs::KinematicSteeringOutput kinematic_seek(RigidBody characterRB, RigidBody targetRB, float maxSpeed)
{
	MovementOutputs::KinematicSteeringOutput output;
	float orientation;

	glm::vec2 seekVec = targetRB.position - characterRB.position;
	seekVec = glm::normalize(seekVec);
	seekVec *= maxSpeed;
	orientation = atan2(seekVec.y, seekVec.x);

	output.linearVelocity = seekVec;
	output.rotVelocity = orientation;

	return output;
}
 
MovementOutputs::KinematicSteeringOutput kinematic_flee(RigidBody characterRB, RigidBody targetRB, float maxSpeed)
{
	return MovementOutputs::KinematicSteeringOutput();
}

MovementOutputs::DynamicSteeringOutput dynamic_seek(RigidBody characterRB, RigidBody targetRB, float maxLinearAccel)
{
	return MovementOutputs::DynamicSteeringOutput();
}

MovementOutputs::DynamicSteeringOutput dynamic_arrive(RigidBody characterRB, RigidBody targetRB, float maxLinearAccel, float maxSpeed, float slowRadius, float targetRadius, float timeToTarget)
{
	return MovementOutputs::DynamicSteeringOutput();
}
