#include "Projectils.h"

const float g = 9.8f;

Projectils::Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, float Damping):
Particle(masa, Pos, Vel, Accerelacion,Damping)
{
}

Projectils::Projectils(float masa, Vector3D Pos, Vector3D Vel, Vector3D Accerelacion, physx::PxShape* shape, float Damping) :
	Particle(masa, Pos, Vel, Accerelacion, shape, Damping)
{

}

void Projectils::pRelentizado(double dt) {
	//Vector3D newV = vel + Vector3D(g,g,g) * dt;
	//Vector3D newPos = Vector3D(pose.p) + vel * dt + (Vector3D(g, g, g) * dt * dt * 1/2);

	//vel = newV;
	//pose.p = newPos.toPxVec3();

	integrate(dt);
	
}
