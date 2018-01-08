//Particle.cpp
#include <array>
#include <iostream>
#include <cstdio>
#include <string>

#include "Particle.h"

Particle::Particle()
{
	particle_ID = 0;
	mass=1;
	pos={0,0};
	vel={0,0};
}

Particle::Particle(unsigned int ID, long double m, long double xi, long double yi, long double vxi, long double vyi)
{
	printf("A custom particle has been created with mass=%Lfkg pos=(%Lf,%Lf) and vel=(%Lf,%Lf)\n", m,xi,yi,vxi,vyi);
	//std::cin.get();
	particle_ID = ID;
	mass=m;
	pos={xi,yi};
	vel={vxi,vyi};
}

void Particle::setID(unsigned int ID)
{
	particle_ID = ID;
}

unsigned int Particle::getID() const
{
	return particle_ID;
}

void Particle::setMass(long double new_Mass)
{
	mass = new_Mass;
}

long double Particle::getMass() const
{
	return mass;
}

//Pass array as @param array<long double>& vector_name
void Particle::setPos(const std::array<long double, 2>& new_Pos)
{
	for (unsigned int i = 0; i < sizeof(pos)/sizeof(pos[0]); i++)
	{
		pos.at(i) = new_Pos.at(i); // Use .at() because checks bounds
	}
}

std::array<long double, 2> Particle::getPos() const
{
	return pos;
}

void Particle::printPos() const
{
	for (unsigned int i = 0; i < sizeof(pos)/sizeof(pos[0]); i++)
	{
		std::cout << this->getPos().at(i) << '\n';
	}
}

void Particle::setVel(const std::array<long double, 2>& new_Vel)
{
	for (unsigned int i = 0; i < sizeof(vel)/sizeof(vel[0]); i++)
	{
		vel.at(i) = new_Vel.at(i); // Use .at() because checks bounds
	}
}

std::array<long double, 2> Particle::getVel() const
{
	return vel;
}