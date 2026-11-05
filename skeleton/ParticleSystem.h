#pragma once
#include "ParticleGenerator.h"
#include "ForceGenerator.h"
class ParticleSystem
{
	//En el sistema de particulas se tiene un vector de particulas junto con su uptade y el generador de particulas
private:
	std::vector<Particle*> v_particle;
	std::vector<ForceGenerator*> forces;
	std::vector<ParticleGenerator*> generators;
	
	float t_emisiones;
	float maxDistance = 1e9f;

	int type = 1;

public:
	ParticleSystem(float emisiones = 10.0f);
	~ParticleSystem();
	void update(double dt);
	void setMaxDistance(float d) { maxDistance = d; }

	void setType(int t) { type = t; }
	void addForce(ForceGenerator* f) { forces.push_back(f); }

	void addGenerator(ParticleGenerator* g);
	void removeGenerator(ParticleGenerator* g);
	void setGeneratorActive(int index, bool active);
	void toggleGenerator(int index);
};

