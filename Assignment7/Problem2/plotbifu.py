from read_plot import *
import matplotlib
matplotlib.rcParams['legend.fancybox'] = True
import matplotlib.pyplot as plt
from matplotlib import legend

x,y = read_plot("bifu_plot.txt")

plt.scatter(x,y)
plt.ylim( [-0.2,0] )
plt.xlim( [1.06,1.065] )

plt.show()
