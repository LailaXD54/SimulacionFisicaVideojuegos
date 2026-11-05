#include "WindForce.h"

WindForce::WindForce(Vector3D windVel, Vector3D center, Vector3D halfSize, float k1, float k2)
	: windVel(windVel), center(center), halfSize(halfSize), k1(k1), k2(k2) {}

bool WindForce::inside(const Vector3D& p) const {
	return fabs(p.x - center.x) <= halfSize.x &&
		fabs(p.y - center.y) <= halfSize.y &&
		fabs(p.z - center.z) <= halfSize.z;
}

Vector3D WindForce::getForce(Particle* p){
	if (!inside(p->getPos())) return Vector3D(0, 0, 0);
	Vector3D dv = getWindVel(p->getPos()) - p->getVel();
	return dv * k1 + dv * (k2 * dv.magnitude());
}