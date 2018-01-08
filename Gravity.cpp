//Gravity.cpp
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>

#include "Gravity.h"

//long double G = 6.67408e-11; // m3kg-1s-2
long double G = 1;

long double mag(const std::array<long double, 2> vec)
// Returns the norm of the vector
// that the array represents
{
	long double mag_squared = 0;
	long double magnitude;
	//c++11 syntax for loop to iterate through container
	for (const auto &component : vec)
	{
		mag_squared += pow(component,2.0);
	}
	magnitude = sqrt(mag_squared);
	return magnitude;
}

std::array<long double, 2> scalar_mult(const long double a, const std::array<long double, 2> vec)
//Multiplies scalar to a vector
//If scalar isn't finite, output is (0,0)
//TODO: implement with std::transform
{
	std::array<long double, 2> new_vec;
	if (!std::isfinite(a))
	{
		new_vec = {0,0};
	}
	else
	{
		unsigned int i = 0;
		for (const auto &element : vec)
		{
			new_vec[i] = a*element;
			i++;
		}
	}
	

	return new_vec;
}

std::array<long double, 2> add_vectors(const std::array<long double,2> vec1, const std::array<long double,2> vec2)
{
	std::array<long double, 2> new_vec;
	for (unsigned int i = 0; i < new_vec.size(); i++)
	{
		new_vec[i] = vec1[i] + vec2[i];
	}
	return new_vec;
}

std::array<long double, 2> sep_vec(const std::array<long double, 2> pos1, const std::array<long double, 2> pos2)
// Calculates the separation vector
{
	std::array<long double, 2> sep_vec;

	for (unsigned int i = 0; i < sizeof(pos1)/sizeof(pos1[0]); i++)
	{
		sep_vec.at(i) = pos1.at(i)-pos2.at(i); // Use .at() because checks bounds
	}

	return sep_vec;
}

std::array<long double, 2> grav_accel(const long double m2, const std::array<long double, 2> pos1, const std::array<long double, 2> pos2)
// Calculates acceleration to adjust velocity
// for gravitational force
{
	//Determine separation vector and related values
	std::array<long double, 2> r = sep_vec(pos1,pos2);
	std::array<long double, 2> r_hat = scalar_mult(pow(mag(r),-1),r);
	long double r_2 = pow(mag(r),2);
	
	std::array<long double, 2> acceleration = scalar_mult(-G*m2/r_2,r_hat);
	//printf("pos1=(%Lf,%Lf),pos2=(%Lf,%Lf),r=(%Lf,%Lf),accel=(%Lf,%Lf)\n",
	//	pos1[0],pos1[1],pos2[0],pos2[1],r[0],r[1],acceleration[0],acceleration[1]);
	return acceleration;
}

/*
std::array<long double, 2> time_integrate(Particle part, std::array<long double, 2> (*fprime)(std::array<long double, 2>)) {

}*/
