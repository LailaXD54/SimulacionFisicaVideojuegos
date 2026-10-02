#pragma once
#include "Particle.h"
class Projectils :
    public Particle
{
public:
    Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, float Damping = 1.0f);
    Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, physx::PxShape* shape, float Damping = 1.0f);

    void pRelentizado(double dt);

    void hitScan();

};

