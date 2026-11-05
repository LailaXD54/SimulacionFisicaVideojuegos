#include "ExplosionForce.h"

ExplosionForce::ExplosionForce(Vector3D c, float K, float R, float tau)
	: c(c), K(K), R(R), tau(tau) {}

void ExplosionForce::update(double dt) {
	if (!exploding) return;
	t += dt;
	if (t > 4 * tau) exploding = false;
}

Vector3D ExplosionForce::getForce(Particle* p){
	if (!exploding) return Vector3D(0, 0, 0);
	Vector3D d = p->getPos() - c;
	float r = d.magnitude();
	if (r >= R || r < 0.001f) return Vector3D(0, 0, 0);
	return d * (K / (r * r)) * std::exp(-t / tau);
}