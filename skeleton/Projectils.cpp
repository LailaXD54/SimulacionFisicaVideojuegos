#include "Projectils.h"

Projectils::Projectils(float masa, Vector3D Pos, Vector3D Dir, float vel, float simVel, float gravedad) :
	Particle(masa, Pos, Dir, Vector3D(0, 0, 0)), gravedad(gravedad), velocidad(vel), vel_sim(simVel)
{

}

Projectils::Projectils(float masa, Vector3D Pos, Vector3D Dir, physx::PxShape* shape, float vel, float simVel, float gravedad) :
	Particle(masa, Pos, Dir, Vector3D(0, 0, 0), shape), gravedad(gravedad), velocidad(vel), vel_sim(simVel)
{

}


void Projectils::calculateGravity(float realVel, float simVel) {
	float ratio = simVel / realVel;
	simGravity = gravedad * (ratio * ratio);
}


void Projectils::disparar(double dt) {
	calculateGravity(velocidad, vel_sim);

	acc = Vector3D(0, simGravity, 0);

	Particle::integrateSemiEuler(dt);
}