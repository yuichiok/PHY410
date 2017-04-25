import sys
import matplotlib.pyplot as plt
from read_plot import read_plot

n = sys.argv[1]

string = "./data/trajfile_cpp_" + str(n) + ".data"
[x,y] = read_plot(string)
plt.plot(x,y)
plt.show()
