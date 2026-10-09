#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(Vector3D pos, Vector3D vel, Vector4 color, physx::PxShape* shape, float tam, float time) {

}

void ParticleSystem::update(double dt){
	


	for (Particle* p : v_particle){
		if (p != nullptr) {
			p->integrateSemiEuler(dt);
		}
	}
}

