import sys
import matplotlib.pyplot as plt
from read_plot_3d import read_plot_3d

string = sys.argv[1]

[x,y,z] = read_plot(string)
plt.plot(x,y,z)
plt.show()
