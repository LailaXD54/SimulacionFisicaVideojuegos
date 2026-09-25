#include "P0S_Scene.h"
#include "Vector3D.h"

void P0S_Scene:: init(){
    /*
	// Ejemplo: Creación de una esfera usando las utilidades de render existentes
    physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));

    m_transform = physx::PxTransform(Vector3D(0.0f, 0.0f, 0.0f).toPxVec3());

    // Se registra el RenderItem exactamente como en la plantilla original
    m_renderItem = new RenderItem(shape, &m_transform, Vector4(1.0f, 0.0f, 0.0f, 1.0f)); //esfera roja
	*/

	//Reto A 
	RetoA();

	//Reto B
	//RetoB();
}

void P0S_Scene::update(double dt) {
	
}

void P0S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {
}

void P0S_Scene::cleanup() {
	for (RenderItem* item : m_renderItems) {
		if (item) item->release();
	}
	m_renderItems.clear();
	m_transforms.clear();
}

void P0S_Scene::RetoA() {
	Vector3D cero;
	Vector3D u (3.0f, 0.0f, 0.0f);
	Vector3D v (0.0f, 4.0f, 0.0f);
	Vector3D w = u.cross(v);

	int mult =2;

	u = u.normalize() * mult;
	v = v.normalize() * mult;
	w = w.normalize() * mult;

	u = u * 5.0f;
	v = v * 5.0f;
	w = w * 5.0f;

	physx::PxShape* p1 = CreateShape(physx::PxSphereGeometry(1.0f));

	m_transforms.push_back(physx::PxTransform(u.toPxVec3()));
	m_transforms.push_back(physx::PxTransform(v.toPxVec3()));
	m_transforms.push_back(physx::PxTransform(w.toPxVec3()));
	m_transforms.push_back(physx::PxTransform(cero.toPxVec3()));


	m_renderItems.push_back(new RenderItem(p1, &m_transforms[0], Vector4(1, 0, 0, 1))); // rojo
	m_renderItems.push_back(new RenderItem(p1, &m_transforms[1], Vector4(0, 1, 0, 1))); // verde
	m_renderItems.push_back(new RenderItem(p1, &m_transforms[2], Vector4(0, 0, 1, 1))); // azul
	m_renderItems.push_back(new RenderItem(p1, &m_transforms[3], Vector4(1, 1, 1, 1)));
}

void P0S_Scene::RetoB(){
	Vector3D pos;
	Vector3D d (0.0f, 0.0f, 1.0f);
	physx::PxShape* p1 = CreateShape(physx::PxSphereGeometry(2.0f));
	
	Vector3D P1(2.0f, 0.0f, 3.0f);
	Vector3D P2(-4.0f, 0.0f, 1.0f);
	Vector3D P3(0.0f, 0.0f, -5.0f);
	Vector3D P4(3.0f, 0.0f, 0.0f);
	std::vector<Vector3D> puntos = { P1, P2, P3, P4 };

	m_transforms.reserve(4);
	m_renderItems.reserve(4);

	for (int i = 0; i < 4;++i) {
		Vector3D v = puntos[i] - pos;
		float dot = d.dot(v);

		Vector4 color;
		if (dot > 0.0f) color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		else if (dot < 0.0f) color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		else color = Vector4(1.0f, 1.0f, 0.0f, 1.0f);

		physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(0.4f));
		m_transforms.push_back(physx::PxTransform(puntos[i].toPxVec3()));
		m_renderItems.push_back(new RenderItem(shape, &m_transforms.back(), color));
	}
}