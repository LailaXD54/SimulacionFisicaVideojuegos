#pragma once
#include <PxPhysics.h>
#include "RenderUtils.hpp"
#include "Vector3D.h"

class Particle
{
public: //cambiar para que sea la gravedad que se cambie
	Particle(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion,float Damping = 1.0f, float time = 10.0f);
	Particle(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, physx::PxShape* shape, float Damping = 1.0f, float time = 10.0f);
	~Particle();

	void integrate(double t);

	void integrateSemiEuler(double t);

	void integrateVerlet(double t);

	void setColor(Vector4 color);

	bool isAlive() { return alive; }

	Vector3D getPos() { return Vector3D(pose.p); }

	void updateLife(double dt);

	Vector4 getColor() const;

	void addForce(const Vector3D& f) { force = force + f; }
	float getMass() const { return masa; }
	Vector3D getVel() const { return vel; }
	float getInvMass() const { return masa > 0 ? 1.0f / masa : 0.0f; }

protected:
	Vector3D vel;
	Vector3D acc;
	float d; //entre 0 y 1
	physx::PxTransform pose;
	
	Vector3D posAnt;
	float masa;
	RenderItem* renderItem = nullptr;

	float lifeTime;

	float timeRemain;
	bool alive = true;

	Vector3D force = Vector3D(0, 0, 0);
};

