#pragma once
#include <PxPhysics.h>
#include <cmath>

class Vector3D
{
public:
	float x, y, z;
	Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}
	Vector3D(const physx::PxVec3& v): x(v.x), y(v.y), z(v.z) {}
	
	//Getters y setters
	float getX() const { return x; }
	float getY() const { return y; }
	float getZ() const { return z; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void setZ(float z) { this->z = z; }

	//Operadores
	Vector3D& operator=(const Vector3D& other) {
		if (this != &other) {
			x = other.x; y = other.y; z = other.z;
		}
		return *this;
	}
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
	Vector3D& operator+=(const Vector3D& other) {
		x += other.x; y += other.y; z += other.z;
		return *this;
	}
	//Conversiones a PxVec3
	explicit operator physx::PxVec3() const {
		return physx::PxVec3(x, y, z);
	}
	physx::PxVec3 toPxVec3() const {
		return physx::PxVec3(x, y, z);
	}

	//Funciones de utilidad
	float magnitude() const {
		return std::sqrt(x * x + y * y + z * z);
	}
	Vector3D normalize() const {
		float mag = magnitude();
		if (mag == 0.0f) return Vector3D(0.0f, 0.0f, 0.0f);
		float inv = 1.0f / mag;
		return Vector3D(x * inv, y * inv, z * inv);
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

