#pragma once
#include "ForceGenerator.h"
class WindForce :
    public ForceGenerator
{
protected:
	Vector3D windVel, center, halfSize;
	float k1, k2;

	bool inside(const Vector3D& p) const;
	virtual Vector3D getWindVel(const Vector3D& pos) { return windVel; }

public:
	WindForce(Vector3D windVel, Vector3D center, Vector3D halfSize, float k1, float k2 = 0);

	Vector3D getForce(Particle* p) override;
};

