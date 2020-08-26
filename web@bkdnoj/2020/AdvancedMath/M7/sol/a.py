from math import sqrt

ERROR = 1e-9

def solve(r, x, y, xp, yp):
    dx = abs(xp - x) 
    dy = abs(yp - y)
    d = sqrt(dx**2 + dy**2)
    k = d//(2*r)
    #
    if abs( (2*r)*k - d) <= ERROR:
        print( int(k) )
    else:
        print( int(k + 1) )
    

if __name__ == "__main__":
    t = int(input())
    for tt in range(t):
        r, x, y, xp, yp = map(int, input().split())
        solve(r, x, y, xp, yp)