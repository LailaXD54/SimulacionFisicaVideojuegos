#pragma once
#include "Scene.h"
#include "Projectils.h"
class P2S_Scene :
    public Scene
{
public:
    explicit P2S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void keyPress(unsigned char key, const physx::PxTransform& cameraTransform) override;

    void cleanup() override;

    void write();

private:
    std::vector<Projectils*> v_pro;
};

