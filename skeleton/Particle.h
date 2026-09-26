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

	void integrateSemiEuler(double t);

	void integrateVerlet(double t);
private:
	Vector3D vel;
	Vector3D acc;
	float d; //entre 0 y 1
	physx::PxTransform pose;
	
	Vector3D posAnt;

	RenderItem* renderItem = nullptr;
};

