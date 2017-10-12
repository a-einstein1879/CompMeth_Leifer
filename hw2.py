import matplotlib.pyplot as plt
import numpy as np
import math as math
import time

# Plot the curve
def problem1():
    # points per cirle
    ppc = 360
    
    #number of circles
    nOC = 1
    tetta = np.linspace(0, nOC * 2 * math.pi, nOC * ppc)
    x = 2 * np.cos(tetta) + np.cos(2 * tetta)
    y = 2 * np.sin(tetta) + np.sin(2 * tetta)
    plt.plot(x, y)
    plt.show()
    
    nOC = 5
    tetta = np.linspace(0, nOC * 2 * math.pi, nOC * ppc)
    r = tetta ** 2
    x = r * np.cos(tetta)
    y = r * np.sin(tetta)
    plt.plot(x, y)
    plt.show()
    
    nOC = 12
    tetta = np.linspace(0, nOC * 2 * math.pi, nOC * ppc)
    r = np.exp(np.cos(tetta)) - 2 * np.cos(4 * tetta) + np.sin(tetta / 15) ** 5
    x = r * np.cos(tetta)
    y = r * np.sin(tetta)
    plt.plot(x, y)
    plt.show()
    return 0

# Feigenbaum plot
def problem2():
    # r = 0..4
    # x = r * x * (1 - x)
    # number of steps
    nOS = 1000
    # starting value of x
    x = 0.5
    
    #coefficient iteration parameters
    n = 0
    rmin = 1
    rmax = 4
    rstep = 0.005
    nr = int((rmax - rmin) / rstep)
    fp = np.empty(nr, dtype = float)
    
    for n in range(0, nr):
        r = rmin + rstep * n
        for i in range(1, nOS):
            x = r * x * (1 - x)
        fp[n] = x
    plt.plot(np.arange(rmin, rmax, rstep), fp, 'ko')
    plt.show()
    return 0

# Mandelbrot set
def problem3():
    # 100 iterations
    # z = z ** 2 + c
    # number of iterations
    nOI = 100
    
    # limits and steps
    xmin  = -2
    xmax  =  2
    xstep =  0.001
    nx    = int((xmax - xmin) / xstep) + 1
    ymin  = -2
    ymax  =  2
    ystep =  0.001
    ny    = int((ymax - ymin) / ystep) + 1
    print("Checking for limits %d < X < %d, %d < Y < %d with the step dx = %.2f, dy = %.2f\nnx = %i, ny = %i" % (xmin, xmax, ymin, ymax, xstep, ystep, nx, ny))
    
    # set picture variable
    mset = np.zeros((nx, ny), dtype = int)
    
    t = time.time()
    # check all points on the grid
    for l in range(0, nx):
        for m in range(0, ny):
            #constant for set
            real = xmin + xstep * l
            imaginary = ymin + ystep * m
            c = complex(real, imaginary)
            #print("\nc = %.2f + %.2fi" % (c.real, c.imag))
            
            z = complex(0, 0)
            isSet = bool(1)
            breakStep = 0
            for n in range(0, nOI):
                z = z ** 2 + c
                if (abs(z) > 2):
                    #print("Is not set\nz(%i) = %.2f + %.2fi,\t|z| = %.2f" % (n, z.real, z.imag, abs(z)))
                    isSet = 0
                    breakStep = n
                    break
        
            if (isSet):
                #print("is set %i, %i" % (l, m))
                mset[l, m] = nOI
            else:
                #print("is not set %i, %i. step = %i" % (l, m, breakStep))
                mset[l, m] = breakStep

    #print(mset)
    plt.imshow(mset)
    plt.gray()
    plt.show()
    elapsed = time.time() - t
    print("Elapsed time %.2f sec" % (elapsed))
    return 0

