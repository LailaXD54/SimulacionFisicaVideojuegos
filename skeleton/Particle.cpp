#include "Particle.h"
#include <iostream>
#include <PxPhysicsAPI.h>

Particle::Particle(Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, float Damping)
	: vel(Vel), 
	pose(Pos.toPxVec3()),
	acc(Accerelacion),
	d(Damping),
	posAnt(Pos.toPxVec3())
{
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));
	renderItem = new RenderItem(shape, &pose, Vector4(1, 0, 1, 1));
}

Particle::~Particle() {
	renderItem->release();
	renderItem = nullptr;
}

void Particle::integrate(double t) {
	Vector3D newVel = (vel + acc * t) * std::pow(d,t);
	Vector3D newPos = Vector3D(pose.p) + vel * t;

	vel = newVel;
	pose.p = newPos.toPxVec3();

	acc = 0;
}

void Particle::integrateSemiEuler(double t) {
	Vector3D newVel = (vel + acc * t) * std::pow(d, t);
	Vector3D newPos = Vector3D(pose.p) + newVel * t;

	vel = newVel;
	pose.p = newPos.toPxVec3();

	acc = 0;
}

void Particle::integrateVerlet(double t) {	
	Vector3D posA = pose.p;
	posA = Vector3D(pose.p) * 2.0f - posAnt + acc * t * t;
	posAnt= pose.p;
	vel = (Vector3D(pose.p) - posAnt) / (2.0f * t);
	pose.p = posA.toPxVec3();

	std::cout << vel <<" "<<pose.p << std::endl;

	acc = 0;
}