#include "SpringForce.h"

SpringForce::SpringForce(Vector3D anchor, float k, float restLenght, float b, bool elastic) : anchor(anchor), k(k), restLength(restLenght), b(b), elastic(elastic) {
}
SpringForce::SpringForce(Particle* other, float k, float restLenght, float b, bool elastic) : other(other), k(k), restLength(restLenght), b(b), elastic(elastic) {
}

Vector3D SpringForce:: getForce(Particle* p) {
    //Posición del otro extremo
    Vector3D otherPos = (other != nullptr) ? other->getPos() : anchor;

    //Vector y distancia actual
    Vector3D dir = p->getPos() - otherPos;
    float dist = dir.magnitude();

    //Evitar división por cero
    if (dist < 1e-6f) return Vector3D(0, 0, 0);

    Vector3D u = dir / dist;

    //Ley de Hooke
    float stretch = dist - restLength;

    //Goma elástica: solo actúa si se estira
    if (elastic && stretch < 0.0f) return Vector3D(0, 0, 0);

    //Amortiguado  
    Vector3D otherVel = (other != nullptr) ? other->getVel() : Vector3D(0, 0, 0);
    float relVel = (p->getVel() - otherVel).dot(u);

    return u * (-k * stretch - b * relVel);
};