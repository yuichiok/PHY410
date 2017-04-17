import matplotlib.pyplot as plt

from fft import fft
from fft import fft_power
from numpy import array
import math
import time

plotfirst = False

if plotfirst == False :
    # make some fake data :

    N = 1024
    f = 10.0
    m = 0

    x = array([ float(i) for i in xrange(N) ] )
    y = array([ math.sin(-2*math.pi*f* xi / float(N))  for xi in x ])
    
    #y = array([ math.sin(-2*math.pi*f* xi / float(N)) + m*xi  for xi in x ])
    
    #y = array([ xi for xi in x ])
    Y = fft(y)
    
    powery = fft_power(Y)
    powerx = array([ float(i) for i in xrange(len(powery)) ] )
    

    Yre = [math.sqrt(Y[i].real**2 + Y[i].imag**2) for i in xrange(N)]

    s1 = plt.subplot(3, 1, 1)
    plt.plot( x, y )
    plt.xlim([0,N])

    '''
    s2 = plt.subplot(3, 1, 2)
    s2.set_autoscalex_on(False)
    plt.plot( x, Yre )
    plt.xlim([0,20])
    
    s3 = plt.subplot(3, 1, 3)
    s3.set_autoscalex_on(False)
    plt.plot( powerx, powery )
    plt.xlim([0,20])
    '''
    
    s2 = plt.subplot(3, 1, 2)
    s2.set_autoscalex_on(False)
    plt.plot( x, Yre )
    plt.xlim([0,20])

    
    s2 = plt.subplot(3, 1, 3)
    s2.set_autoscalex_on(False)
    plt.plot( powerx, powery )
    #p2, = plt.plot( x, Yre )
    #s2.legend( [p1, p2], ["Power", "Magnitude"] )
    plt.xlim([0,N/4])
    plt.yscale('log')


    plt.show()
