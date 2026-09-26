#include "Particle.h"
#include <iostream>
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
	Vector3D newVel = (vel + acc * t) * d * std::pow(d, t);
	Vector3D newPos = Vector3D(pose.p) + newVel * t;

	vel = newVel;
	pose.p = newPos.toPxVec3();

	acc = 0;
}

void Particle::integrateVerlet(double t) {
	Vector3D currPos = Vector3D(pose.p);
	Vector3D newPos = currPos + (currPos - posAnt) *(1.0f - d) + acc * (t * t);

	posAnt = currPos;
	pose.p = newPos.toPxVec3();

	vel = (newPos - posAnt) / t;

	acc = 0;
}