#include "ForceGenerator.h"

class SpringForce : public ForceGenerator {
    Particle* other = nullptr;
    Vector3D anchor;
    float k, restLength, b;
    bool elastic;         // true → solo tracción (goma elástica)
public:
    SpringForce(Vector3D anchor, float k, float restLenght, float b = 0.0f, bool elastic = false);
    SpringForce(Particle* other, float k, float restLenght, float b = 0.0f, bool elastic = false);

    Vector3D getForce(Particle* p) override;

    float getK() const { return k; }
    void setK(float K) { k = K; }
};

