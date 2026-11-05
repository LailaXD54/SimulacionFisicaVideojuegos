#pragma once
#include "ForceGenerator.h"
class ExplosionForce :
    public ForceGenerator
{
private:
	Vector3D c;
	float K, R, tau, t = 0;
	bool exploding = false;
public:
	ExplosionForce(Vector3D c, float K, float R, float tau);

	void trigger() { t = 0; exploding = true; }

	void update(double dt) override;

	Vector3D getForce(Particle* p) override;
};

