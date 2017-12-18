import math
import matplotlib.pyplot as plt
import numpy as np

def f(t):
    return math.exp(-t ** 2)

def E(x):
    a = 0.0
    b = x
    N = 50
    dx = (b - a) / N
    total = 0
    for i in range(1, N):
        total = total + f(a + i * dx)
    I = dx * (1 / 2 * f(a) + 1 / 2 * f(b) + total)
    return I

def problem1():
    delta = 0.1
    b = 3
    x = np.linspace(0, b, b / delta)
    Ev = np.empty([int(b / delta), 1], dtype = float)
    t = 0
    for i in np.nditer(x):
        Ev[t] = E(i)
        t = t + 1
    plt.plot(x, Ev)
    plt.show()
