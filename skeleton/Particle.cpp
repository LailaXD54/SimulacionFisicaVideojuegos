#include "Particle.h"
#include <iostream>
Particle::Particle(Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, float Damping)
	: vel(Vel), 
	pose(Pos.toPxVec3()),
	acc(Accerelacion),
	d(Damping)
{
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));
	renderItem = new RenderItem(shape, &pose, Vector4(1, 0, 1, 1));
}

Particle::~Particle() {

	renderItem->release();
	renderItem = nullptr;
}

void Particle::integrate(double t) {
	Vector3D newVel = (vel + acc * t) * d;
	Vector3D newPos = Vector3D(pose.p) + vel * t;

	vel = newVel;
	pose.p = newPos.toPxVec3();	

	std::cout << "Vel == (" << vel.x << ", " << vel.y << ", " << vel.z << ")" << std::endl;
	std::cout << "Pos == (" << newPos.x << ", " << newPos.y << ", " << newPos.z << ")" << std::endl;

	acc = 0;
}