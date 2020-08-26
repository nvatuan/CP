from math import ceil

T = int(input())

def f(x):
    return x**2 + x

def opt(n, d):
    xL = 0;
    xR = n;

    while xL < xR:
        #print("xL = %d xR = %d" % (xL, xR))
        xMid = (xL + xR + 1)//2
        if f(xMid) > d:
            xR = xMid - 1
        else:
            xL = xMid

    return xL

while T > 0:
    T -= 1
    ##################
    n, d = map(int, input().split())
    x = opt(n, d)
    #print(x)
    if x + ceil(d/(x+1)) <= n:
        print("YES")
    else:
        print("NO")