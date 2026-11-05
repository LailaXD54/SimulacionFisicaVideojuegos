#pragma once
#include "Scene.h"
#include "RenderUtils.hpp"
#include <vector>

#include "Projectils.h"

class P0S_Scene : public Scene
{
public:
    explicit P0S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;
    void cleanup() override;
    void update(double dt) override;
    void keyPress(unsigned char key, const physx::PxTransform& cameraTransform) override;

private:
    std::vector<Projectils*> v_pro;

    RenderItem* boton = nullptr;
    physx::PxTransform* botonPose = nullptr;
    physx::PxShape* botonShape = nullptr;
};

