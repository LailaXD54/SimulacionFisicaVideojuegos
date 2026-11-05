#include "P1S_Scene.h"

void P1S_Scene::init() {
	p_sys.push_back(new ParticleSystem(10.0f));  // manguera
	p_sys.push_back(new ParticleSystem(20.0f));  // niebla
	p_sys.push_back(new ParticleSystem(80.0f));  //confeti

	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));
	physx::PxShape* shapeConfeti = CreateShape(physx::PxBoxGeometry(0.15f, 0.02f, 0.15f));

	ParticleGenerator* manguera = new ParticleGenerator(Vector3D(0, 0, 0), Vector3D(0, 20, 0), Vector4(0, 0.5, 1, 1), 0.1f, 5.0f, shape);
	manguera->setDesvVel(Vector3D(2, 2, 2));
	manguera->setVelGause(true);
	manguera->setPosGause(false);

	ParticleGenerator* niebla = new ParticleGenerator(Vector3D(0, 0, 0), Vector3D(0, 0, 0), Vector4(1, 1, 1, 1), 0.05f, 8.0f, shape, false);
	niebla->setPosRange(Vector3D(-30, 0, -30), Vector3D(30, 5, 30));
	niebla->setVelRange(Vector3D(-0.5, -0.2, -0.5), Vector3D(0.5, 0.2, 0.5));
	niebla->setPosGause(true);
	niebla->setVelGause(true);
	niebla->setFading({ 0.1f,0.1f,0.1f,0.0f });

	ParticleGenerator* confeti = new ParticleGenerator(Vector3D(0, 30, 0), Vector3D(0, -18, 0), Vector4(1, 1, 1, 1), 2.0f, 4.0f, shapeConfeti);
	confeti->setDesvVel(Vector3D(6, 4, 6));
	confeti->setVelGause(true);
	confeti->setPosGause(false);
	confeti->setColorGause(true);
	
	
	p_pg.push_back(manguera);
	p_pg.push_back(niebla);
	p_pg.push_back(confeti);
}

void P1S_Scene::update(double dt) {
	for (int i = 0; i < p_pg.size(); i++) {
		p_sys[i]->update(p_pg[i], dt);
	}
}

void P1S_Scene::cleanup(){
	if (!p_pg.empty()) {
		for (ParticleGenerator* g : p_pg) delete g;
		p_pg.clear();
	}

	if (!p_sys.empty()) {
		for (auto s : p_sys) delete s;
		p_sys.clear();
	}
}

