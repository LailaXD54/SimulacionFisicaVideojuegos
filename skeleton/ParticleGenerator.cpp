#include "ParticleGenerator.h"
#include <chrono>
ParticleGenerator::ParticleGenerator(Vector3D pos, Vector3D vel, Vector4 color, float tam,
    float lifeTime, physx::PxShape* shape, bool gausse)
    : pos(pos), vel(vel), gausse(gausse),
    desvVel(0, 0, 0), desvPos(0, 0, 0),
    velMin(0, 0, 0), velMax(0, 0, 0),
    posMin(0, 0, 0), posMax(0, 0, 0),
    color(color), tam(tam), lifeTime(lifeTime), shape(shape),
    vel_g(true), pos_g(false), color_g(false),
    colorfade({ 0, 0, 0, 0 })
{
    _mt.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

Particle* ParticleGenerator::getNewParticle() {
    Vector3D this_vel = vel;
    Vector3D this_pos = pos;
    Vector4  this_color = color;

    if (gausse) {
        if (vel_g)
            this_vel = Vector3D(vel.x + desvVel.x * g(_mt),
                vel.y + desvVel.y * g(_mt),
                vel.z + desvVel.z * g(_mt));
        if (pos_g)
            this_pos = Vector3D(pos.x + desvPos.x * g(_mt),
                pos.y + desvPos.y * g(_mt),
                pos.z + desvPos.z * g(_mt));
    }
    else {
        if (vel_g)
            this_vel = Vector3D(getValues(velMin.x, velMax.x),
                getValues(velMin.y, velMax.y),
                getValues(velMin.z, velMax.z));
        if (pos_g)
            this_pos = Vector3D(getValues(posMin.x, posMax.x),
                getValues(posMin.y, posMax.y),
                getValues(posMin.z, posMax.z));
    }

    if (color_g)
        this_color = Vector4(g(_mt), g(_mt), g(_mt), color.w);

    Particle* p = new Particle(masa, this_pos, this_vel, accel, shape, damping, lifeTime);
    p->setColor(this_color);
    return p;
}

float ParticleGenerator::getValues(float posA, float posB) {
    return posA + (posB - posA) * u(_mt);
}