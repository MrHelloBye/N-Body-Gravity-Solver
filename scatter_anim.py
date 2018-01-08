# -*- coding: utf-8 -*-
"""
Created on Tue Nov 29 17:26:58 2016

@author: mrhel
"""
import csv
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

#Open output file and read its contents
ifile = open('output.csv', "rb")
file = np.loadtxt(ifile, delimiter=',',skiprows=1)

data = {} #dict to contain ordered pairs for each time
times = [] #make a list of times to be keys of the dict
rownum = 0
for row in file:
    if rownum != 0:
    	time = row[0]
    	if time not in times:
    		times.append(time)
    		data.update({time:[]})
    	data[time].append([row[2],row[3]])
    rownum += 1

ifile.close()

#Plot and animate the scatter plot
fig = plt.figure()

#The callback function
def update_plot(i, fig, scat): # i is the frame number
    
    scat.set_offsets((data[times[i]]))  # update the data
    return scat,

#Create and stylize the axis
ax = fig.add_subplot(111)
ax.grid(True, linestyle = '-', color = '0.75')
ax.set_xlim([-20,20])
ax.set_ylim([-20,20])

x = [0,1,2] # this essentially controls the color somehow
y = [0,0,0]
scat = plt.scatter(x,y,c=x)
scat.set_alpha(0.8)

#fargs is the arguments after the frame number that get passed to the callback function
#frames is the number of frames to be animated
#interval is the length of time in milliseconds between frames

anim = animation.FuncAnimation(fig, update_plot, fargs = (fig,scat), frames = int(input("Number of frames: ")), interval = int(input("Time interval (ms): ")))

plt.show()

anim.save('gravity.gif', fps=30, dpi=150, writer='imagemagick')