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

		v_pro.push_back(new Projectils(1.0f, Vector3D(GetCamera()->getEye()), Vector3D(GetCamera()->getDir()) * 5, Vector3D(GetCamera()->getDir()), 1.0f,0.25f,0.0f));
		break;

	case 'm':
		cout << "m" << endl;
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