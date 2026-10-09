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

	Vector3 posA, posB;

	//caracteristicas de las particulas
	Vector4 color;
	float tam;
	physx::PxShape* shape = nullptr;

	std::mt19937 _mt;
	std::uniform_real_distribution<double> u;
	std::normal_distribution<double> g;
	
public:
	ParticleGenerator();
	//Particle getNewParticle();

	//Particle update(double dt);
	//Particle Uniforme();
	//Particle Gaus();

	void setGaus(bool g) { gausse = g; }

 };



