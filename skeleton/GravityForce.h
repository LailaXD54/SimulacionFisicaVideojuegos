#pragma once
#include "ForceGenerator.h"
class GravityForce :
    public ForceGenerator
{
private:
	Vector3D g;
public:
	GravityForce(Vector3D g) : g(g) {}
	Vector3D getForce(Particle* p) override { return g * p->getMass(); }
};

