#pragma once
#include "ParticleGenerator.h"

class ParticleSystem
{
	//En el sistema de particulas se tiene un vector de particulas junto con su uptade y el generador de particulas
private:
	std::vector<Particle*> v_particle;
	ParticleGenerator* _pg = nullptr;

public:
	ParticleSystem(Vector3D pos, Vector3D vel, Vector4 color,physx::PxShape* shape , float tam, float time);

	void update(double dt);
	
};

