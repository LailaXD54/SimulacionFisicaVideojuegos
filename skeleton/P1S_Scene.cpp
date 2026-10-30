#include "P1S_Scene.h"

void P1S_Scene::init() {
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));

	Vector3D pos(0,10,0);
	Vector3D vel (0, 0.5f, 0);
	Vector3D desv(1.5f, 5.5f, 5.5f);
	Vector4 color (1.0f, 0.5f, 1.0f, 1);
	float tam = 0.1f;
	float time = 5.0f;

	Vector3D posA(0, 10, 0);
	Vector3D posB(10, 20, 10);

	p_pg = new ParticleGenerator(pos, vel, desv, color, tam, time, shape, posA, posB);

	p_ps = new ParticleSystem(100.0f);

	p_pg->setGaus(true);

	p_pg->setVelGause(true);
	p_pg->setColorGause(false);
	p_pg->setPosGause(true);

	p_pg->setFading({ 0.0f,0.0f,0.1f,0.0f });
}

void P1S_Scene::update(double dt) {
	p_ps->update(p_pg,dt);
}

void P1S_Scene::cleanup(){
	if (p_ps) {
		delete p_ps;
		p_ps = nullptr;
	}

}

