#pragma once
#include "ParticleGenerator.h"
#include "ForceGenerator.h"
class ParticleSystem
{
	//En el sistema de particulas se tiene un vector de particulas junto con su uptade y el generador de particulas
private:
	std::vector<Particle*> v_particle;
	
	float t_emisiones;
	float accumulador;
	float maxDistance = 100.0f;

	int type = 1;

	std::vector<ForceGenerator*> forces;
public:
	ParticleSystem(float emisiones = 10.0f);
	~ParticleSystem();
	void update(ParticleGenerator* _pg, double dt);
	void setMaxDistance(float d) { maxDistance = d; }
	int getNumParticles() const { return v_particle.size(); }

	void setType(int t) { type = t; }
	void addForce(ForceGenerator* f) { forces.push_back(f); }
};

