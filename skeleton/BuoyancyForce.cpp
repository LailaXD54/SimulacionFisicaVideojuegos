#include "BuoyancyForce.h"
BuoyancyForce::BuoyancyForce(float height, float volume, float liquidDensity, float surfaceY, float gravity)
	: height(height), volume(volume), liquidDensity(liquidDensity), surfaceY(surfaceY), gravity(gravity) {
}

Vector3D BuoyancyForce::getForce(Particle* p) {
    float h = p->getPos().y;   // posición vertical del objeto
    float h0 = surfaceY;
    float immersed;

    if (h - h0 > height * 0.5f) {
        immersed = 0.0f;
    }
    else if (h0 - h > height * 0.5f) {
        immersed = 1.0f;
    }
    else {
        immersed = (h0 - h) / height + 0.5f;
    }

    float E = gravity * liquidDensity * volume * immersed;
    return Vector3D(0.0f, E, 0.0f);
}