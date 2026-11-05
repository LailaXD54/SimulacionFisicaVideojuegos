#pragma once
#include "Scene.h"
#include "Particle.h"
#include "Vector3D.h"

#include "ParticleSystem.h"
#include "ParticleGenerator.h"
#include <vector>

#include "GravityForce.h"
#include "WindForce.h"
#include "WhirlForce.h"
#include "ExplosionForce.h"

class P1S_Scene :
    public Scene
{
public:

    explicit P1S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void keyPress(unsigned char key, const physx::PxTransform& cameraTransform) override;

    void update(double dt) override;

    void cleanup() override;

private:
    void setMode(int m);

    ParticleSystem* psLight = nullptr;
    ParticleSystem* psHeavy = nullptr;
    ParticleGenerator* genLight = nullptr;
    ParticleGenerator* genHeavy = nullptr;

    GravityForce* gravity = nullptr;
    WindForce* wind = nullptr;
    WhirlForce* whirl = nullptr;
    ExplosionForce* explosion = nullptr;

    std::vector<ForceGenerator*> allForces;
    int mode = 0;
};

