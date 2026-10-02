#include "P1S_Scene.h"

void P1S_Scene::init() {
	p_particle = new Particle(1.0f,Vector3D(0, 0, 0), Vector3D(0, 100, 0), Vector3D(0, 250, 0), 1.0f);
}

void P1S_Scene::update(double dt) {
	
	p_particle->integrateSemiEuler(dt);
}

void P1S_Scene::cleanup(){
	if (p_particle) {
		delete p_particle;
		p_particle = nullptr;
	}

}