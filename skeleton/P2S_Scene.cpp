#include "P2S_Scene.h"
#include <iostream>
using namespace std;

void P2S_Scene::init() {

}

void P2S_Scene::update(double dt) {
	for (Projectils* item : v_pro) {
		if (item) item->update(dt);
	}
}

void P2S_Scene::keyPress(unsigned char key, const physx::PxTransform& cameraTransform) {
	switch (key) {
	case 'b':
		v_pro.push_back(new Projectils(1.0f, Vector3D(GetCamera()->getEye()), Vector3D(GetCamera()->getDir()) * 5, Vector3D(GetCamera()->getDir()), 1.0f,0.25f));
		break;

	case 'm':
		v_pro[v_pro.size() - 1]->addMasa(-1.0f);
		break;
	case 'M':
		v_pro[v_pro.size() - 1]->addMasa(1.0f);
		break;
	case 'n':
		v_pro[v_pro.size() - 1]->addVel(Vector3D(-GetCamera()->getDir()));
		break;
	case 'N':
		v_pro[v_pro.size() - 1]->addVel(Vector3D(GetCamera()->getDir()));
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