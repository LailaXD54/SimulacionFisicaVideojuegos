#pragma once
#include "ForceGenerator.h"
// BuoyancyForce.h
class BuoyancyForce : public ForceGenerator {
    float height, volume, liquidDensity, surfaceY, gravity;
public:
    BuoyancyForce(float height, float volume, float liquidDensity, float surfaceY, float gravity = 9.8f);

    Vector3D getForce(Particle* p) override;
};