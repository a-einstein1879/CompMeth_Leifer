import random
import matplotlib.pyplot as plt
import numpy as np
#from visual import *

def getNewCoordinates(x, y, xmax, ymax):
    newx = x
    newy = y
    r = random.randint(0, 3)
    if (r == 0):
        newx = x + 1
    elif (r == 1):
        newx = x - 1
    elif (r == 2):
        newy = y + 1
    elif (r == 3):
        newy = y - 1
    else:
        print("Random is not working")

    if (newx < 0 or newy < 0 or newx > xmax or newy > ymax):
        return getNewCoordinates(x, y, xmax, ymax)
    return (newx, newy)


def problem1(N, L):
    x = L / 2
    y = L / 2
    pos = np.empty([2, N], dtype = int)
    #display(center=[0.5,0.5])
    for i in range(0, N):
        x, y = getNewCoordinates(x, y, L, L)
        pos[0, i] = x
        pos[1, i] = y
    plt.plot(pos[0, :], pos[1, :], '.')
    plt.show()
    #sphere(pos=(1, 2, 1), radius=0.5)
    return 0
