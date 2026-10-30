#pragma once
#include "Vector3D.h"
#include "Particle.h"
#include <random>
class ParticleGenerator
{
	//modelo de la particula: su pos, color, velocidad, tiene una distribución asignada
	// Distribuciones probabilstica:
	//Dis.Uniforme: se define 2 puntos (a,b), entre esos 2 puntos, tiene la misma prob de aparecer
		//Es util para simular la lluvia, una manguera
	//Dis.Gaussiana/Normal: campana de gaus, se tiene un valor x, el medio, y otro de desviación (x,ó), apartir del cual esta el 68.3% de los valores
	//la desviación lo hace para que los extremos haya menos problabilidad de que aparezcan las particuas
		//Es util para simular distribuciones realistas

	//xp = x0 + uniforme <- lo mismo para 'y' y 'z'

	//se puede usar para el gaus, std::mt19937 _mt;
	// std::uniform_real_distribution<double> u(0,1);
	// std::normal_distribution<double> g (0,1);
	//g(_mt)

private:
	Vector3D pos; //posicion de la fuente
	Vector3D vel;
	bool gausse;

	Vector3D desv;
	Vector3D posA, posB;

	//caracteristicas de las particulas
	Vector4 color;
	float tam;
	float lifeTime;
	physx::PxShape* shape = nullptr;

	std::mt19937 _mt;
	std::uniform_real_distribution<double> u{ 0.0, 1.0 };
	std::normal_distribution<double> g{ 0.0, 1.0 };

	bool vel_g, pos_g, color_g;

	Vector4 colorfade;
	
public:
	//pos, vel, desv, color, tam, lifeTime, *shape, gause
	ParticleGenerator(Vector3D pos, Vector3D vel, Vector3D desv, Vector4 color, float tam, float lifeTime, physx::PxShape* shape,Vector3D posA, Vector3D posB,bool gausse = true);
	
	Particle* getNewParticle();

	void setGaus(bool g) { gausse = g; }
	void setVelRange(Vector3D mn, Vector3D mx) { posA = mn; posB = mx; }

	float getValues(float posA, float posB);

	void setColorGause(bool c) { color_g = c; }
	void setVelGause(bool c) { vel_g = c; }
	void setPosGause(bool c) { pos_g = c; }

	void setFading(Vector4 color) { colorfade = color; }

	Vector4 getFading() const { return colorfade; }
 };