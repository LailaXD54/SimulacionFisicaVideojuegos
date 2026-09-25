#include "P1S_Scene.h"

void P1S_Scene::init() {
	p_particle = new Particle(Vector3D(0, 0, 0), Vector3D(0, 10, 0), Vector3D(0, 1, 0), 1.0f);
}

void P1S_Scene::update(double dt) {
	p_particle->integrate(dt);
}

void P1S_Scene::cleanup(){

}