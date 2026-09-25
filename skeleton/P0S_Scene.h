#pragma once
#include "Scene.h"
#include "RenderUtils.hpp"
class P0S_Scene : public Scene
{
public:
    explicit P0S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void keyPress(unsigned char key, const physx::PxTransform& camera) override;

    void cleanup() override;


    void RetoA(); //coordenadas

    void RetoB();
private:
    std::vector<physx::PxTransform> m_transforms;
    std::vector<RenderItem*> m_renderItems;
};

