#include "P2S_Scene.h"
#include <iostream>
using namespace std;

void P2S_Scene::init() {
	p_sys = new ParticleSystem(80.0f);
	physx::PxShape* shapeConfeti = CreateShape(physx::PxBoxGeometry(0.15f, 0.02f, 0.15f));
	
	ParticleGenerator* confeti = new ParticleGenerator(Vector3D(0, 30, 0), Vector3D(0, -18, 0), Vector4(1, 1, 1, 1), 2.0f, 4.0f, shapeConfeti);
	confeti->setDesvVel(Vector3D(6, 4, 6));
	confeti->setVelGause(true);
	confeti->setPosGause(false);
	confeti->setColorGause(true);
	p_pg = confeti;
}

void P2S_Scene::update(double dt) {
	if(p_sys && p_pg) p_sys->update(p_pg, dt);
	
}

void P2S_Scene::keyPress(unsigned char key, const physx::PxTransform& cameraTransform) {

}


void P2S_Scene::cleanup() {
	if (p_sys) { 
		delete p_sys; 
		p_sys = nullptr;
	}

	if (p_pg) {
		delete p_pg;
		p_pg = nullptr;
	}

}