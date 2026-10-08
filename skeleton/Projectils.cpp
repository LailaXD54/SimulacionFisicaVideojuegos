#include "Projectils.h"

const float g = 9.8f;

Projectils::Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, float Damping, float factor, float gravedad):
Particle(masa, Pos, Vel, Accerelacion,Damping), factor(factor), gravedad(gravedad)
{

}

Projectils::Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, physx::PxShape* shape, float Damping, float factor, float gravedad) :
	Particle(masa, Pos, Vel, Accerelacion, shape, Damping)
{

}

void Projectils::pRelentizado(double dt) {
	Vector3D vel_s = velSim();

	pose.p += vel_s.toPxVec3() * dt;
	vel = vel - (Vector3D(0,g,0) * factor * dt);
	
}

Vector3D Projectils::velSim() {
	return vel * factor;
}

float Projectils::masaSim() {
	return masa / factor;
}