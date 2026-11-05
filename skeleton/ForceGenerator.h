#pragma once
#include "Particle.h"
class ForceGenerator{
public:
	virtual ~ForceGenerator() = default;
	virtual Vector3D getForce(Particle* p) = 0;
	virtual void update(double dt) {}
	bool active = true;
};

