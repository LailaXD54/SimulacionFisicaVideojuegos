#include "WhirlForce.h"

WhirlForce::WhirlForce(Vector3D center, Vector3D halfSize, float K, float k1, float k2)
	: WindForce(Vector3D(0, 0, 0), center, halfSize, k1, k2), K(K) {}

Vector3D WhirlForce::getWindVel(const Vector3D& p) {
	return Vector3D(-(p.z - center.z),
		50.0f - (p.y - center.y),
		p.x - center.x) * K;
}