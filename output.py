import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

filename ="output1D.txt"

data=pd.read_csv(filename, skiprows=4, delimiter=" ")

energy=data["TotalEnergy"]
magnetisation = data["Magnetisation"]

bins= 4

fig,ax1 = plt.subplots()
ax1.hist(energy, bins=3, color ="mediumpurple", edgecolor="black", alpha=0.7)
ax1.set_xlabel("Energy")
ax1.set_ylabel("Frequency")

fig,ax2 = plt.subplots()
ax2.hist(magnetisation, bins=bins, color ="paleturquoise", edgecolor="black", alpha=0.7)
ax2.set_xlabel("Magnetisation")
ax2.set_ylabel("Frequency")

plt.show()
