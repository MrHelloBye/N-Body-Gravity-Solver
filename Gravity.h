//Gravity.h
#ifndef Gravity_H

#include <array>

#include "Particle.h"

//Vector operations
long double mag(const std::array<long double, 2> vec);
std::array<long double, 2> scalar_mult(const long double a, const std::array<long double,2> vec);
std::array<long double, 2> add_vectors(const std::array<long double,2> vec1, const std::array<long double,2> vec2);
std::array<long double, 2> sep_vec(const std::array<long double, 2> pos1, const std::array<long double, 2> pos2);

//Numerical integration
std::array<long double, 2> time_integrate(Particle part, std::array<long double, 2> (*fprime)(std::array<long double, 2>));

//Equations of motion
std::array<long double, 2> grav_accel(const long double m2, const std::array<long double, 2> pos1, const std::array<long double, 2> pos2);

#endif
