#include "MuelleScene.h"
#include <iostream>

void MuelleScene::init() {
	//Fuerzas

	gravity = new GravityForce(Vector3D(0, -10, 0));
	buoyancy = new BuoyancyForce(2.0f, 8.0f,5.0f,0.0f);
	spring = new SpringForce(Vector3D(0,10,0), 1.0f, 0.5f, 0.2f, true);

	allForces = { gravity, buoyancy, spring };

	//Sistemas de partículas
	ps_muelle = new ParticleSystem(30.0f);
	ps_muelle->addForce(gravity);
	ps_muelle->addForce(spring);

	ps_bouyancy = new ParticleSystem(30.0f);
	ps_bouyancy->addForce(gravity);


	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(0.6f));

	pg_muelle = new ParticleGenerator(Vector3D(-5, 0, 0), Vector3D(0, 15, 0),
		Vector4(1.0f, 0.0f, 0.0f, 1.0f), 0.3f, 6.0f, shape);
	pg_muelle->setVelGause(true);
	pg_muelle->setDesvVel(Vector3D(0.3f, 0.3f, 0.3f));
	pg_muelle->setPosGause(true);
	pg_muelle->setDesvPos(Vector3D(5, 5, 5));
	pg_muelle->setMass(1.0f);

	pg_bouyancy = new ParticleGenerator(Vector3D(-5, 0, 0), Vector3D(0, 15, 0),
		Vector4(1.0f, 0.0f, 0.0f, 1.0f), 0.3f, 6.0f, shape);
	pg_bouyancy->setVelGause(true);
	pg_bouyancy->setDesvVel(Vector3D(0.3f, 0.3f, 0.3f));   
	pg_bouyancy->setPosGause(true);
	pg_bouyancy->setDesvPos(Vector3D(5, 5, 5));
	pg_bouyancy->setMass(1.0f);

	ps_muelle->addGenerator(pg_muelle);
	ps_bouyancy->addGenerator(pg_bouyancy);

	physx::PxShape* boxShape = CreateShape(physx::PxBoxGeometry(5.0f, 5.0f, 5.0f));
	box = new Particle(1, Vector3D(0, 0, 0), Vector3D(0), Vector3D(0), boxShape, 1, 1e9f);
	box->setColor(Vector4(1, 0, 0, 1));

	physx::PxShape* recShape = CreateShape(physx::PxBoxGeometry(20.0f, 2.0f, 20.0f));
	Particle* test = new Particle(1, Vector3D(0, 10, 0), Vector3D(0), Vector3D(0), recShape, 1, 1e9f);
	test->setColor(Vector4(0, 0, 1, 1));

}

void MuelleScene::keyPress(unsigned char key, const physx::PxTransform& cameraTransform) {
	//switch (key) {
	//case '1':
	//	gravity->active = !gravity->active;
	//	break;
	//case '2':
	//	buoyancy->active = !buoyancy->active;
	//	break;
	//case '3':
	//	spring->active = !spring->active;
	//	break;
	//default:
	//	break;
	//}
}

void MuelleScene::update(double dt) {
	for (ForceGenerator* f : allForces) {
		f->update(dt);
	}

	//ps_muelle->update(dt);

	box->addForce(gravity->getForce(box));
	box->addForce(buoyancy->getForce(box));
	box->integrateSemiEuler(dt);

	std::cout << "Box pos: " << box->getPos()<<"\n";
}

void MuelleScene::cleanup() {
	delete ps_muelle;  ps_muelle = nullptr;
	delete ps_bouyancy;  ps_bouyancy = nullptr;
	delete pg_muelle; pg_muelle = nullptr;
	delete pg_bouyancy; pg_bouyancy = nullptr;
	delete box; box = nullptr;

	for (ForceGenerator* f : allForces) delete f;
	allForces.clear();
	gravity = nullptr; buoyancy = nullptr; spring = nullptr;
}
