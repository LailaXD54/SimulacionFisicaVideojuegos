#pragma once
#include <PxPhysics.h>
#include "RenderUtils.hpp"
#include "Vector3D.h"

class Particle
{
public:
	Particle(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion,float Damping = 1.0f, float time = 10.0f);
	Particle(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, physx::PxShape* shape, float Damping = 1.0f, float time = 10.0f);
	~Particle();

	void integrate(double t);

	void integrateSemiEuler(double t);

	void integrateVerlet(double t);

	void setColor(Vector4 color);

protected:
	Vector3D vel;
	Vector3D acc;
	float d; //entre 0 y 1
	physx::PxTransform pose;
	
	Vector3D posAnt;
	float masa;
	RenderItem* renderItem = nullptr;

	float lifeTime;
};

