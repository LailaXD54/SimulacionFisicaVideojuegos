#include "ForceGenerator.h"

class SpringForce : public ForceGenerator {
    Particle* other = nullptr;
    Vector3D anchor;
    float k, restLength;
    bool elastic;         // true → solo tracción (goma elástica)
public:
    SpringForce(Vector3D anchor, float k, float restLenght, bool elastic = false);
    SpringForce(Particle* other, float k, float restLenght, bool elastic = false);

    Vector3D getForce(Particle* p) override;
};

