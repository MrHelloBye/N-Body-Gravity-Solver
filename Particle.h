#ifndef Particle_H
#define Particle_H

#include <string>
#include <array>
#include <string>

class Particle
{
private:
	unsigned int particle_ID;
	long double mass;
	std::array<long double, 2> pos;
	std::array<long double, 2> vel;

public:
	Particle();
	Particle(unsigned int ID, long double m, long double xi, long double yi, long double vxi, long double vyi);
	
	void setID(unsigned int n);
	unsigned int getID() const;

	void setMass(const long double mass);
	long double getMass() const;

	void setPos(const std::array<long double, 2>& new_Pos);
	std::array<long double, 2> getPos() const;
	void printPos() const;

	void setVel(const std::array<long double, 2>& new_Vel);
	std::array<long double, 2> getVel() const;
	// void printVel() const;
	
};

#endif
