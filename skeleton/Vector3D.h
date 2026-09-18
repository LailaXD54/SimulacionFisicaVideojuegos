#pragma once
#include <PxPhysics.h>

using namespace physx;
class Vector3D
{
private:
	float x, y, z;

public:
	Vector3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
	
	//Getters y setters
	float getX() const { return x; }
	float getY() const { return y; }
	float getZ() const { return z; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void setZ(float z) { this->z = z; }

	//Operadores
	Vector3D operator+(const Vector3D& other) const
	{
		return Vector3D(x + other.x, y + other.y, z + other.z);
	}
	Vector3D operator-(const Vector3D& other) const
	{
		return Vector3D(x - other.x, y - other.y, z - other.z);
	}
	Vector3D operator*(float scalar) const
	{
		return Vector3D(x * scalar, y * scalar, z * scalar);
	}

	//Conversiones a PxVec3
	explicit operator PxVec3() const {
		return PxVec3(x, y, z);
	}
	PxVec3 toPxVec3() const {
		return PxVec3(x, y, z);
	}

	//Funciones de utilidad
	float magnitude() const {
		return sqrt(x * x + y * y + z * z);
	}
	Vector3D normalize() const {
		float mag = magnitude();
		if (mag == 0) return Vector3D(0, 0, 0);
		return Vector3D(x / mag, y / mag, z / mag);
	}
	float dot(const Vector3D& other) const {
		return x * other.x + y * other.y + z * other.z;
	}
	Vector3D cross(const Vector3D& other) const {
		return Vector3D(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}


};

