#include "dynamic_seperation.h"

DynamicSeperation::~DynamicSeperation()
{
	delete dynamicEvade;
}

DynamicSteeringOutput DynamicSeperation::getSteering()
{
	DynamicSteeringOutput result, accumResult;
	
	for (auto it = targetRBs.begin(); it != targetRBs.end(); it++) {
		if(dynamicEvade == nullptr)
			dynamicEvade = new DynamicEvade(characterRB, *it, maxPrediction, maxAcceleration, safeRadius, decayCoef);
		else {
			dynamicEvade->targetRB = *it;
		}

		result = dynamicEvade->getSteering();
		accumResult.linearAccel += result.linearAccel;
		accumResult.rotAccel += result.rotAccel;
	}

	return accumResult;
}
