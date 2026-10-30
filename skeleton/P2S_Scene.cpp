#include "P2S_Scene.h"
#include <iostream>
using namespace std;

void P2S_Scene::init() {

}

void P2S_Scene::update(double dt) {
	for (Projectils* item : v_pro) {
		if (item) item->disparar(dt);
	}
}

void P2S_Scene::keyPress(unsigned char key, const physx::PxTransform& cameraTransform) {

	float masa=0, vel=0, simVel = 0, gravedad=-9.81f;
	switch (key) {
	case 'b': { //disparo 
		masa = 100.0f;
		vel = 500.0f;
		simVel = 499.0f;
		gravedad = -5;
		write();
		break;
	}

	case 'm': { //proyectil fuerte
		masa = 15.0f;
		vel = 100.0f;
		simVel = 10.0f;

		write();
		break;
	}
	case 'n': { //bubble
		masa = 1.0f;
		vel = 10.0f;
		simVel = 2.0f;
		gravedad = -4.81f;

		write();
		break;
	}
	

	default:
		break;
	}

	v_pro.push_back(new Projectils(masa, Vector3D(GetCamera()->getEye()), Vector3D(GetCamera()->getDir()), vel, simVel, gravedad));


	
}

void P2S_Scene:: write() {

	cout << "________________________" << endl;
}

void P2S_Scene::cleanup() {
	for (Projectils* item : v_pro) {
		if (item) {
			delete item;
			item = nullptr;
		}
	}
	v_pro.clear();
}