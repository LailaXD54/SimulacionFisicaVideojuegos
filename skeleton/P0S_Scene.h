#pragma once
#include "Scene.h"
#include "RenderUtils.hpp"
#include "ParticleSystem.h"
#include "ParticleGenerator.h"
#include "ForceGenerator.h"
#include <vector>

#include "GravityForce.h"
#include "WindForce.h"
#include "WhirlForce.h"
#include "ExplosionForce.h"

class P0S_Scene : public Scene
{
public:
    explicit P0S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;
    void cleanup() override;
    void update(double dt) override;
    void keyPress(unsigned char key, const physx::PxTransform& cameraTransform) override;

private:
    void setMode(int m);

    // Dos sistemas: partículas ligeras y pesadas
    ParticleSystem* psLight = nullptr;
    ParticleSystem* psHeavy = nullptr;
    ParticleGenerator* genLight = nullptr;
    ParticleGenerator* genHeavy = nullptr;

    // Fuerzas
    GravityForce* gravity = nullptr;
    WindForce* wind = nullptr;
    WhirlForce* whirl = nullptr;
    ExplosionForce* explosion = nullptr;

    std::vector<ForceGenerator*> allForces;
    int mode = 0;
};

