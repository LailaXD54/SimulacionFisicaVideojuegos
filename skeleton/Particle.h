#pragma once
#include <PxPhysics.h>
#include "RenderUtils.hpp"
#include "Vector3D.h"

class Particle
{
public:
	Particle(Vector3D Pos, Vector3D Vel, Vector3D Accerelacion,float Damping);
	~Particle();

	void integrate(double t);

private:
	Vector3D vel;
	Vector3D acc;
	float d; //entre 0 y 1
	physx::PxTransform pose;
	
	RenderItem* renderItem = nullptr;
};

