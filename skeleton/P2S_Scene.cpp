#include "P2S_Scene.h"
#include <iostream>
using namespace std;

void P2S_Scene::init() {

}

void P2S_Scene::update(double dt) {
	for (Projectils* item : v_pro) {
		if (item) item->pRelentizado(dt);
	}
}

void P2S_Scene::keyPress(unsigned char key, const physx::PxTransform& cameraTransform) {
	switch (key) {
	case 'b':
		cout << "disparando" << endl;
		//Projectils* test = new Projectils(1.0f, Vector3D(GetCamera()->getEye()), Vector3D(GetCamera()->getDir()), Vector3D(GetCamera()->getDir()));

		v_pro.push_back(new Projectils(1.0f, Vector3D(GetCamera()->getEye()), Vector3D(GetCamera()->getDir()) * 5, Vector3D(GetCamera()->getDir())));
		break;

	case 'm':
		break;
	case 'M':
		break;

	case 'v':
		break;
	case 'V':
		break;

	default:
		break;
	}
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