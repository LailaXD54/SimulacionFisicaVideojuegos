#include "SpringForce.h"

Vector3D SpringForce:: getForce(Particle* p) {
    // 1. Posición del otro extremo (anclaje o partícula)
    Vector3D otherPos = (other != nullptr) ? other->getPosition() : anchor;

    // 2. Vector y distancia actual
    Vector3D dir = p->getPosition() - otherPos;
    float dist = dir.magnitude();

    // 3. Evitar división por cero
    if (dist < 1e-6f) return Vector3D(0, 0, 0);

    // 4. Dirección normalizada
    Vector3D u = dir / dist;

    // 5. Ley de Hooke: F = -k · (dist - restLength) · û
    float stretch = dist - restLength;

    // 6. Goma elástica: solo actúa si se estira
    if (elastic && stretch < 0.0f) return Vector3D(0, 0, 0);

    return u * (-k * stretch);
}
};