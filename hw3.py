def intFactorial(n):
    number = int(1)
    for i in range(1, n + 1):
        number = number * i
    return number

def floatFactorial(n):
    number = float(1)
    for i in range(1, n + 1):
        number = number * i
    return number

def problem1():
    print("Hello, user!")
    n = int(raw_input("Please input the number you want to calculate factorial of: "))
    print("Integer calculated factorial is %d" % intFactorial(n))
    print("Float   calculated factorial is %f" % floatFactorial(n))
    return 0

def f(x):
    f = float(x * (x - 1))
    return f

def problem2():
    for i in range(2, 15):
        delta = float(10 ** (-i))
        dirF = (f(1 + delta) - f(1)) / delta
        print("delta = %.15f, derivative = %.15f" % (delta, dirF))
    return
