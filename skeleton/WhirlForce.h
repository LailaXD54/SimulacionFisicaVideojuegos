#pragma once
#include "WindForce.h"
class WhirlForce :
    public WindForce
{
private:
	float K;
public:
	WhirlForce(Vector3D center, Vector3D halfSize, float K, float k1, float k2 = 0);

protected:
	Vector3D getWindVel(const Vector3D& p) override;
};

