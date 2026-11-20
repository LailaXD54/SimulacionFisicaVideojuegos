#pragma once
#include "ForceGenerator.h"
// BuoyancyForce.h
class BuoyancyForce : public ForceGenerator {
    float height, volume, liquidDensity, surfaceY;
public:
    Vector3D getForce(Particle* p) override;  // aplica fórmula del PDF
};