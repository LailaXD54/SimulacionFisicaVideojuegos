#include "ParticleSystem.h"
#include <algorithm>
#include <iostream>

ParticleSystem::ParticleSystem(float emisiones):
	t_emisiones(emisiones) {
}

ParticleSystem::~ParticleSystem() {
	for (Particle* p : v_particle) delete p;
	v_particle.clear();
}

void ParticleSystem::update(double dt){
	for (ParticleGenerator* g : generators) {
		if (!g || !g->active) continue;

		g->acumulador += dt;
		float intervalo = 1.0f / t_emisiones;
		while (g->acumulador >= intervalo) {
			v_particle.push_back(g->getNewParticle());
			g->acumulador -= intervalo;
		}
	}

	for (Particle* p : v_particle) {
		if (!p) continue;

		for (ForceGenerator* f : forces)
			if (f->active) p->addForce(f->getForce(p));

		p->integrateSemiEuler(dt);
		
		p->setColor(p->getColor() - p->getFading()*dt);

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

void ParticleSystem::addGenerator(ParticleGenerator* g) {
	if (g) generators.push_back(g);
}

void ParticleSystem::removeGenerator(ParticleGenerator* g) {
	auto it = std::find(generators.begin(), generators.end(), g);
	if (it != generators.end()) generators.erase(it);
}

void ParticleSystem::setGeneratorActive(int index, bool active) {
	if (index >= 0 && index < (int)generators.size())
		generators[index]->active = active;
}

void ParticleSystem::toggleGenerator(int index) {
	if (index >= 0 && index < (int)generators.size())
		generators[index]->active = !generators[index]->active;
}