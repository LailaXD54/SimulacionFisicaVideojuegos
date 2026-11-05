#include "P1S_Scene.h"
#include <iostream>
#include "SceneManager.h"

void P1S_Scene::init() {
    //las fuerzas
    gravity = new GravityForce(Vector3D(0, -10, 0));
    wind = new WindForce(Vector3D(15, 0, 0), Vector3D(0, 10, 0), Vector3D(25, 25, 25), 1.0f);
    whirl = new WhirlForce(Vector3D(0, 10, 0), Vector3D(25, 25, 25), 0.3f, 1.0f);
    explosion = new ExplosionForce(Vector3D(0, 5, 0), 300.0f, 30.0f, 1.0f);

    allForces = { gravity, wind, whirl, explosion };

    //sistemas de partículas
    psLight = new ParticleSystem(30.0f);
    for (ForceGenerator* f : allForces) {
        psLight->addForce(f);
    }
    psLight->setMaxDistance(150.0f);


    psHeavy = new ParticleSystem(30.0f);
    for (ForceGenerator* f : allForces) {
        psHeavy->addForce(f);
    }
    psHeavy->setMaxDistance(150.0f);

    //generadores
    physx::PxShape* shapeLight = CreateShape(physx::PxSphereGeometry(0.6f));

    genLight = new ParticleGenerator(Vector3D(-5, 0, 0), Vector3D(0, 15, 0),
        Vector4(1.0f, 0.0f, 0.0f, 1.0f), 0.3f, 6.0f, shapeLight);
    genLight->setVelGause(true);
    genLight->setDesvVel(Vector3D(0.3f, 0.3f, 0.3f));
    genLight->setPosGause(true);
    genLight->setDesvPos(Vector3D(5, 5, 5));
    genLight->setMass(1.0f);

    genHeavy = new ParticleGenerator(Vector3D(5, 0, 0), Vector3D(0, 15, 0),
        Vector4(0.0f, 0.0f, 1.0f, 1.0f), 0.3f, 6.0f, shapeLight);
    genHeavy->setVelGause(true);
    genHeavy->setDesvVel(Vector3D(0.3f, 0.3f, 0.3f));
    genHeavy->setPosGause(true);
    genHeavy->setDesvPos(Vector3D(5, 5, 5));
    genHeavy->setMass(5.0f);

    setMode(0);
}

void P1S_Scene::setMode(int m) {
    mode = m;
    // La gravedad siempre activa; el resto según el modo
    gravity->active = true;
    wind->active = (mode == 1);
    whirl->active = (mode == 2);
    explosion->active = (mode == 3);
    const char* names[] = { "Gravedad", "Viento", "Torbellino", "Explosion (pulsa L)" };
    std::cout << "Modo: " << names[mode] << std::endl;
}

void P1S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {
    switch (key) {
    case 'y': setMode(0); break;
    case 'u': setMode(1); break;
    case 'i': setMode(2); break;
    case 'o': setMode(3); break;
    case 'l':
        if (mode == 3) explosion->trigger();
        break;
    case 'p': SceneManager::instance().changeScene("P2S_Scene");
    default:
        break;
    }
}


void P1S_Scene::update(double dt) {
    for (ForceGenerator* f : allForces) f->update(dt);

    psLight->update(genLight, dt);

    psHeavy->update(genHeavy, dt);
}

void P1S_Scene::cleanup(){
    delete psLight;  psLight = nullptr;
    delete psHeavy;  psHeavy = nullptr;
    delete genLight; genLight = nullptr;
    delete genHeavy; genHeavy = nullptr;

    for (ForceGenerator* f : allForces) delete f;
    allForces.clear();
    gravity = nullptr; wind = nullptr; whirl = nullptr; explosion = nullptr;
}

