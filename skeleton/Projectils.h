#pragma once
#include "Particle.h"
class Projectils :
    public Particle
{
private:
    float masa_sim;
    float vel_sim;
    float velocidad;

    float factor;
    float gravedad;
    float simGravity; 

public:
    Projectils(float masa, Vector3D Pos, Vector3D Dir, float vel, float simVel, float gravedad = -9.81f);
    Projectils(float masa, Vector3D Pos, Vector3D Dir, physx::PxShape* shape, float vel, float simVel, float gravedad = -9.81f);

    float getMasa()const { return masa; }
    Vector3D getVel() const { return vel; }

    void calculateGravity(float realVel, float simVel);

    void disparar(double dt);

};

