#pragma once
#include "Scene.h"
#include "Particle.h"
#include "GravityForce.h"
#include "BuoyancyForce.h"
#include "SpringForce.h"

#include "ParticleSystem.h"
#include "ParticleGenerator.h"
#include <vector>


class MuelleScene :
    public Scene
{
public:
	explicit MuelleScene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void keyPress(unsigned char key, const physx::PxTransform& cameraTransform) override;

    void cleanup() override;

private:
    ParticleSystem* ps_muelle = nullptr;
    ParticleGenerator* pg_muelle = nullptr;

    ParticleSystem* ps_bouyancy = nullptr;
    ParticleGenerator* pg_bouyancy = nullptr;

	GravityForce* gravity = nullptr;
	BuoyancyForce* buoyancy = nullptr;
	SpringForce* spring = nullptr;

    std::vector<ForceGenerator*> allForces;

};

