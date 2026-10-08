#pragma once
#include "Particle.h"
class Projectils :
    public Particle
{
private:
    float masa_sim;
    float vel_sim;

    float factor;
    float gravedad;

public:
    Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, float Damping = 1.0f, float factor = 0.25f, float gravedad = 9.81f);
    Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, physx::PxShape* shape, float Damping = 1.0f, float factor = 0.25f, float gravedad = 9.81f);

    void pRelentizado(double dt);

    void hitScan();
    
    Vector3D velSim();

    float masaSim();
};

