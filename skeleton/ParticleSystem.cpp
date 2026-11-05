#include "ParticleSystem.h"
#include <algorithm>
#include <iostream>

ParticleSystem::ParticleSystem(float emisiones):
	t_emisiones(emisiones) {
	accumulador = 0.0f;
}

ParticleSystem::~ParticleSystem() {
	for (Particle* p : v_particle) delete p;
	v_particle.clear();
}

void ParticleSystem::update(ParticleGenerator* _pg,double dt){
	accumulador += dt;
	float intervalo = 1.0f / t_emisiones;
	while (accumulador >= intervalo) {
		v_particle.push_back(_pg->getNewParticle());
		accumulador -= intervalo;
	}

	Vector4 color_fading = _pg->getFading();

	for (Particle* p : v_particle) {
		if (!p) continue;
		p->integrateSemiEuler(dt);
		
		p->setColor(p->getColor() - color_fading*dt);

		p->updateLife(dt);
	}

	auto it = std::remove_if(v_particle.begin(), v_particle.end(),
		[this](Particle* p) {
			if (!p) return true;
			if (!p->isAlive()) { delete p; return true; }
			if (p->getPos().magnitude() > maxDistance) { delete p; return true; }
			return false;
		});
	v_particle.erase(it, v_particle.end());
}

