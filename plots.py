import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

filename1 ="energy_vs_temperature1D.txt"
filename2="magnetisation_vs_temperature1D.txt"

energy=pd.read_csv(filename1, delimiter=" ")
mag=pd.read_csv(filename2, delimiter=" ")

fig,ax1=plt.subplots()
ax1.scatter(energy["Temperature"],energy["AverageEnergy"],color="orchid")
ax1.set_xlabel("Temperature")
ax1.set_ylabel("Average Energy")

fig,ax2=plt.subplots()
ax2.scatter(mag["Temperature"],mag["AverageMagnetisation"],color="darkturquoise")
ax2.set_xlabel("Temperature")
ax2.set_ylabel("Average Magnetisation")

plt.show()

