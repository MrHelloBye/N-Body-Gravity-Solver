#include <cmath>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <typeinfo>
#include <vector>

#include "Gravity.h"
#include "Particle.h"

using namespace std;

int main() {
	//Create vector to store Particles
	vector<Particle> particles;

	//TODO: add option to randomly generate particles with
	// params in given ranges
	
	//Open input file
	ifstream infile("initial_conditions.csv");
	//Create output file
	FILE *output_file;
	output_file = fopen("output.csv", "w");
	fprintf(output_file, "Time,ID,x,y\n");

	long double m, xi, yi, vxi, vyi; char s;
	//Read in initial positions and velocities
	unsigned int ID_counter = 0;
	while ((infile >> m >> s >> xi >> s >> yi >> s >> vxi >> s >> vyi) && (s == ','))
	{
		// This can be done more efficiently if space is preallocated
		particles.push_back(Particle(ID_counter,m,xi,yi,vxi,vyi));
		ID_counter++;
	}
	infile.close();

	//Determine how many particles there are
	unsigned int num_of_particles = particles.size();
	//Get the timestep and duration
	long double dt, duration;
	cout << "What timestep (s) would you like to use?\n";
	cin >> dt;
	cout << "What duration would you like to run the simulation for?\n";
	cin >> duration;

	//TODO: Make a loop that updates velocities and positions for desired time interval
	// and print position of one particle throughout the duration

	//Create vectors to store temporary values
	vector<array<long double, 2>> temp_pos;
	temp_pos.reserve(num_of_particles);
	vector<array<long double, 2>> temp_vel;
	temp_vel.reserve(num_of_particles);
	//Print out gravitational acceleration of all particles
	unsigned int i = 0;
	unsigned int modulus = 1;
	for (long double t = 0; t <= duration; t+=dt)
	{
		// Update the position and velocity for each particle
		for (auto &particle1 : particles) //Doesn't like const because "qualifiers are discarded"
		{
			//Calculate the net acceleration of the particle
			array<long double, 2> net_accel = {0,0};
			for (const auto &particle2 : particles)
			{
				array<long double, 2> accel_contribution = grav_accel(particle2.getMass(),particle1.getPos(),particle2.getPos());
				net_accel = add_vectors(net_accel,accel_contribution);
				//printf("accel cont %u: %Lf\n", particle2.getID(), accel_contribution);
			}
			
			//Calculate the new position and velocity
			array<long double, 2> new_pos = add_vectors(particle1.getPos(),scalar_mult(dt,particle1.getVel()));
			array<long double, 2> new_vel = add_vectors(particle1.getVel(),scalar_mult(dt,net_accel));

			//Set temporary values for the next loop
			temp_pos[particle1.getID()] = new_pos;
			temp_vel[particle1.getID()] = new_vel;
		}
		
		//Update particle positions and velocities and write to file
		//must occur after all new values are calculated for each time step
		for (auto &particle : particles)
		{
			//write the positions of each particle to file every few time steps
			if (fmod(i,modulus) == 0)
			{
				printf("%Lf\n", t);
				fprintf(output_file,"%Lf,%u,%Lf,%Lf\n",t,particle.getID(),particle.getPos()[0],particle.getPos()[1]);
			}

			//Update positions and velocities
			particle.setPos(temp_pos[particle.getID()]);
			particle.setVel(temp_vel[particle.getID()]);
		}

		i++;
	}
	//Clean up and close
	fclose(output_file);
	return 0;
}
