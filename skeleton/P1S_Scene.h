#pragma once
#include "Scene.h"
#include "Particle.h"
#include "Vector3D.h"
class P1S_Scene :
    public Scene
{
public:

    explicit P1S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void cleanup() override;

private:
    Particle* p_particle;


};

