from math import pi
from math import sin
from math import cos

ERROR = 1e-9

def solve(act):
    Ox = 0; Oy = 0; Look = pi/2;
    ##
    for a in act:
        Look += a[0] * (pi/180)
        Ox += a[1] * cos(Look)
        Oy += a[1] * sin(Look)
    ##
    print("%.9f %.9f" % (Ox, Oy))

## Main
if __name__ == "__main__":
    t = int(input())
    for tt in range(t):
        m = int(input())
        act = [ [0]*2 for _ in range(m) ]
        for i in range(0, m):
            act[i] = list(map(float, input().split()))
        ###
        solve(act)