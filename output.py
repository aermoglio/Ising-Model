import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

filename ="output1D.txt"

data=pd.read_csv(filename, skiprows=4, delimiter=" ")

energy=data["TotalEnergy"]

fig,ax = plt.subplots()
ax.hist(energy, bins=15, color ="hotpink", edgecolor="black", alpha=0.7)

plt.show()
