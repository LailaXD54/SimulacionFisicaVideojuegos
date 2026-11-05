#pragma once
#include "Scene.h"
#include "Projectils.h"
#include "ParticleGenerator.h"
#include "ParticleSystem.h"

class P2S_Scene :
    public Scene
{
public:
    explicit P2S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void keyPress(unsigned char key, const physx::PxTransform& cameraTransform) override;

    void cleanup() override;

private:
    ParticleSystem* p_sys = nullptr;
    ParticleGenerator* p_pg = nullptr;
};

