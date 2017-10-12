import math

# Define the time it takes to fall from required height
def problem1():
    g = 9.8
    
    print("Hello, user!\n")
    h = float(raw_input("Please input the height: "))
    t = math.sqrt(2 * h / g)
    print("%f seconds\n" % t)
    return 0

# Define the height of the orbit around Earth knowing the period
def problem2():
    G = 6.67 * math.pow(10, -11)
    M = 9.97 * math.pow(10, 24)
    R = 6371 * math.pow(10, 3)
    
    print("Hello, user!\n")
    T = float(raw_input("Please input required period: "))
    h = (math.pow(G * M * math.pow(T, 2) / 4 / pow(math.pi, 2), 0.33) - R) / 1000
    print("%.2f km\n" % h)
    return 0
