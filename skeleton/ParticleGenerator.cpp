#include "ParticleGenerator.h"
#include <chrono>
ParticleGenerator::ParticleGenerator(Vector3D pos, Vector3D vel, Vector3D desv,
	Vector4 color, float tam, float lifeTime,
	physx::PxShape* shape, Vector3D posA, Vector3D posB, bool gausse) : pos(pos), vel(vel), desv(desv),
	color(color), tam(tam), lifeTime(lifeTime), shape(shape), posA(posA), posB(posB), gausse(gausse), 
    vel_g(true), pos_g(false), color_g(false), colorfade({0,0,0,0}) {

	_mt.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

Particle* ParticleGenerator::getNewParticle() {
    Vector3D this_vel;
    Vector3D this_pos = pos;
    Vector4 this_color = color;

    if (gausse) {

        if (vel_g) {
            // Gaussiana independiente por componente: mu + sigma * N(0,1)
            this_vel = Vector3D(vel.x + desv.x * g(_mt),
                                vel.y + desv.y * g(_mt),
                                vel.z + desv.z * g(_mt));
        }

        if (pos_g) {
            this_pos = Vector3D(pos.x + desv.x * g(_mt),
                pos.y + desv.y * g(_mt),
                pos.z + desv.z * g(_mt));
        }

        if (color_g) {
            this_color = Vector4(g(_mt), g(_mt), g(_mt), 1.0f);
        }
    }
    else {
        // Uniforme 3D: cada componente entre posA y posB
        this_vel = Vector3D(getValues(posA.x, posB.x), getValues(posA.y, posB.y), getValues(posA.z, posB.z));
    }

    // Gravedad fija para todas las partículas: (0, -10, 0)
    Vector3D acc(0.0f, -10.0f, 0.0f);

    Particle* p = new Particle(1.0f, this_pos, this_vel, acc, shape, 1.0f, lifeTime);
    p->setColor(this_color);
    return p;
}

float ParticleGenerator::getValues(float posA, float posB) {
    return posA + (posB - posA) * u(_mt);
}