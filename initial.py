import random

N = 1000 # Number of particles

minmass,maxmass = 0,1
minx,maxx = -10,10
miny,maxy = -10,10
minvx,maxvx = -1,1
minvy,maxvy = -1,1

with open("initial_conditions.csv","w") as f:
	for i in range(N):
		m = random.uniform(minmass,maxmass)
		x = random.uniform(minx,maxx)
		y = random.uniform(miny,maxy)
		vx = random.uniform(minvx,maxvx)
		vy = random.uniform(minvy,maxvy)
		f.write('{},{},{},{},{}\n'.format(m,x,y,vx,vy))