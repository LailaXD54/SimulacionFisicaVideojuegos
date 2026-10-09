#include "Projectils.h"

const float g = 9.8f;

Projectils::Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, float Damping, float factor, float gravedad, bool hitscan):
Particle(masa, Pos, Vel, Accerelacion,Damping), factor(factor), gravedad(gravedad), hitscan(hitscan)
{

}

Projectils::Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, physx::PxShape* shape, float Damping, float factor, float gravedad, bool hitscan) :
	Particle(masa, Pos, Vel, Accerelacion, shape, Damping), factor(factor), gravedad(gravedad), hitscan(hitscan)
{

}

void Projectils::pRelentizado(double dt) {
	Vector3D vel_s = velSim();

	pose.p += vel_s.toPxVec3() * dt;
	vel.setY(vel.getY() - gravedad * factor * dt);
	
}

void Projectils::hitScan(double dt) {
	integrateSemiEuler(dt);
}

Vector3D Projectils::velSim() {
	return vel * factor;
}

float Projectils::masaSim() {
	return masa / (factor * factor);
}

void Projectils::addMasa(float m) {
	masa += m;
}

void Projectils::addVel(Vector3D v) {
	vel += v;
}

void Projectils::update(double dt) {
	if (hitscan) hitScan(dt);
	else pRelentizado(dt);
}