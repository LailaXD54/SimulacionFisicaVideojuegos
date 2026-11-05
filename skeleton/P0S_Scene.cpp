#include "P0S_Scene.h"
#include "SceneManager.h"
#include <iostream>

void P0S_Scene:: init(){
    Vector3D camPos(GetCamera()->getEye());
    Vector3D camDir(GetCamera()->getDir());
    camDir.normalize();
    Vector3D buttonPos = camPos + camDir * 10.0f;

    botonShape = CreateShape(physx::PxBoxGeometry(2.0f, 1.0f, 0.1f));
    botonPose = new physx::PxTransform(buttonPos.toPxVec3());
    boton = new RenderItem(botonShape, botonPose, Vector4(0.2f, 0.8f, 0.2f, 1.0f));
}

void P0S_Scene::update(double dt) {
    for (Projectils* item : v_pro) {
        if (item) item->disparar(dt);
    }
}

void P0S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {
    bool disparar = false;
    float masa = 0, vel = 0, simVel = 0, gravedad = 0;
    if (key == 'b' || key == 'B') {
        masa = 20.0f;
        vel = 60.0f;
        simVel = 20.0f;
        disparar = true;
    }
    if (key == 'n' || key == 'N') {
        masa = 20.0f;
        vel = 60.0f;
        simVel = 20.0f;
        disparar = true;
        gravedad = -90.81;
    }

    if (key == 'p' || key == 'P') {
        SceneManager::instance().changeScene("P1S_Scene");
    }

    if (disparar) {
        v_pro.push_back(new Projectils(masa,Vector3D(GetCamera()->getEye()),Vector3D(GetCamera()->getDir()),vel, simVel, gravedad));
    }
}

void P0S_Scene::cleanup() {
    for (Projectils* item : v_pro) {
        if (item) { delete item; item = nullptr; }
    }
    v_pro.clear();

    if (boton) { boton->release(); boton = nullptr; }
}
