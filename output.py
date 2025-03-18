import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

filename ="output1D.txt"

data=pd.read_csv(filename, skiprows=4, delimiter=" ")

energy=data["TotalEnergy"]
magnetisation = data["Magnetisation"]

bins= 10

fig,ax1 = plt.subplots()
ax1.hist(energy, bins=bins, color ="hotpink", edgecolor="black", alpha=0.7)

fig,ax2 = plt.subplots()
ax2.hist(magnetisation, bins=bins, color ="blue", edgecolor="black", alpha=0.7)

plt.show()
