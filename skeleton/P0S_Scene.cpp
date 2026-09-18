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
	Vector3D u = Vector3D(3.0f, 1.0f, 0.0f);
	Vector3D v = Vector3D(0.0f, 4.0f, 0.0f);
	Vector3D w = u.cross(v);

	u.normalize();
	v.normalize();
	w.normalize();

	u = u * 5.0f;
	v = v * 5.0f;
	w = w * 5.0f;

	physx::PxShape* p1 = CreateShape(physx::PxSphereGeometry(2.0f));
	physx::PxShape* p2 = CreateShape(physx::PxSphereGeometry(2.0f));
	physx::PxShape* p3 = CreateShape(physx::PxSphereGeometry(2.0f));
	
	physx::PxTransform m_transform_0 = physx::PxTransform(u.toPxVec3());
	m_renderItem = new RenderItem(p1, &m_transform_0, Vector4(1.0f, 0.0f, 0.0f, 1.0f));

	physx::PxTransform m_transform_1 = physx::PxTransform(v.toPxVec3());
	m_renderItem = new RenderItem(p2, &m_transform_1, Vector4(0.0f, 1.0f, 0.0f, 1.0f));

	m_transform = physx::PxTransform(w.toPxVec3());
	m_renderItem = new RenderItem(p3, &m_transform, Vector4(0.0f, 0.0f, 1.0f, 1.0f));

}

void P0S_Scene::update(double dt) {
	
}

void P0S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {
}

void P0S_Scene::cleanup() {
	if (m_renderItem) {
		m_renderItem->release(); 
		m_renderItem = nullptr;
	}
}