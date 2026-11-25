#include "MuelleScene.h"
#include <iostream>

void MuelleScene::init() {
	//Fuerzas
	gravity = new GravityForce(Vector3D(0, -10, 0));
	buoyancy = new BuoyancyForce(2.0f, 100.0f,1000.0f,0.0f);
	spring = new SpringForce(Vector3D(0,10,0), 1.0f, 0.5f, 0.2f, true);
	wind = new WindForce(Vector3D(15, 0, 0), Vector3D(0, 10, 0), Vector3D(25, 25, 25), 1.0f);
	allForces = { gravity, buoyancy, spring };

	//Sistemas de partículas
	ps_muelle = new ParticleSystem(30.0f);
	//ps_muelle->addForce(gravity);
	ps_muelle->addForce(spring);

	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(0.6f));

	pg_muelle = new ParticleGenerator(Vector3D(10, 0, 10), Vector3D(0, 15, 0),
		Vector4(1.0f, 1.0f, 0.5f, 1.0f), 0.3f, 6.0f, shape);
	pg_muelle->setVelGause(true);
	pg_muelle->setDesvVel(Vector3D(0.3f, 0.3f, 0.3f));
	pg_muelle->setPosGause(true);
	pg_muelle->setDesvPos(Vector3D(5, 5, 5));
	pg_muelle->setMass(1.0f);

	ps_muelle->addGenerator(pg_muelle);

	physx::PxShape* boxShape = CreateShape(physx::PxBoxGeometry(5.0f, 5.0f, 5.0f));
	box = new Particle(1000, Vector3D(0, 0, 0), Vector3D(0), Vector3D(0), boxShape, 1, 1e9f);
	box->setColor(Vector4(1, 0, 0, 1));

	//water
	physx::PxShape* recShape = CreateShape(physx::PxBoxGeometry(20.0f, 2.0f, 20.0f));
	Particle* test = new Particle(1, Vector3D(0, 10, 0), Vector3D(0), Vector3D(0), recShape, 1, 1e9f);
	test->setColor(Vector4(0, 0, 1, 1));

	ball_1 = new Particle(1, Vector3D(-10, 20, 10), Vector3D(0), Vector3D(0), shape, 1, 1e9f);
	ball_1->setColor(Vector4(0.5f, 0.6, 1, 1));

	ball_2 = new Particle(1, Vector3D(-10, 30, 10), Vector3D(0), Vector3D(0), shape, 1, 1e9f);
	ball_2->setColor(Vector4(1.0f, 0, 0.4f, 1));

	spring_ball_1 = new SpringForce(ball_2, 10.0f, 2.0f, 0.0f, true);
	spring_ball_2 = new SpringForce(ball_1, 10.0f, 2.0f, 0.0f, true);


	allForces.push_back(spring_ball_1);
	allForces.push_back(spring_ball_2);
}

void MuelleScene::keyPress(unsigned char key, const physx::PxTransform& cameraTransform) {
	switch (key) {
	case 'g':
		active_wind = !active_wind;
		break;
	case 'z':{
		spring_ball_1->setK(spring_ball_1->getK() -0.1f);
		std::cout << "k :" << spring_ball_1->getK() << "\n";
		break;
	}
	case 'x': {
		spring_ball_1->setK(spring_ball_1->getK() + 0.1f);
		std::cout << "k :" << spring_ball_1->getK() << "\n";
		break;
	}
	case 'm': {
		box->setMass(box->getMass() - 50.0f);
		std::cout << "MASA :" << box->getMass() << "\n";
		break;
	}
	case 'M': {
		box->setMass(box->getMass() + 50.0f);
		std::cout << "MASA :" << box->getMass() << "\n";
		break;
	}
	case 'f': {
		buoyancy->setVolume(buoyancy->getVolume() - 5.0f);
		std::cout << "VOL :" << buoyancy->getVolume() << "\n";
		break;
	}
	case 'F': {
		buoyancy->setVolume(buoyancy->getVolume() + 5.0f);
		std::cout << "VOL :" << buoyancy->getVolume() << "\n";
		break;
	}
	default:
		break;
	}
}

void MuelleScene::update(double dt) {
	for (ForceGenerator* f : allForces) {
		f->update(dt);
	}

	ps_muelle->update(dt);

	box->addForce(gravity->getForce(box));
	box->addForce(buoyancy->getForce(box));
	box->integrateSemiEuler(dt);

	ball_1->addForce(spring_ball_1->getForce(ball_1));
	ball_2->addForce(spring_ball_2->getForce(ball_2));

	if (active_wind) {
		ball_1->addForce(wind->getForce(ball_1));
	}

	ball_1->integrateSemiEuler(dt);
	ball_2->integrateSemiEuler(dt);
	//std::cout << "Box pos: " << box->getPos()<<"\n";
}

void MuelleScene::cleanup() {
	delete ps_muelle;  ps_muelle = nullptr;
	delete ps_bouyancy;  ps_bouyancy = nullptr;
	delete pg_muelle; pg_muelle = nullptr;
	
	delete box; box = nullptr;

	for (ForceGenerator* f : allForces) delete f;
	allForces.clear();
	gravity = nullptr; buoyancy = nullptr; spring = nullptr;
}
