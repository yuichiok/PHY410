import sys
import matplotlib.pyplot as plt
from read_plot import read_plot

string = sys.argv[1]

[x,y] = read_plot(string)
plt.plot(x,y)
plt.show()
