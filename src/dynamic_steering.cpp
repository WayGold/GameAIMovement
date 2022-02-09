#include "dynamic_steering.h"

DynamicOutput::DynamicOutput(glm::vec2 i_linearAccel, float i_rotAccel) : linearAccel(i_linearAccel), rotAccel(i_rotAccel)
{
}

DynamicOutput::~DynamicOutput()
{
}
