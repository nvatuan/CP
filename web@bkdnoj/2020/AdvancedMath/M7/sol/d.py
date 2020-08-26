ERROR = 1e-9

def ccw(p0, p1, p2):
    return (p1[0] - p0[0]) * (p2[1] - p0[1]) - (p2[0] - p0[0]) * (p1[1] - p0[1])

def solve(point):
    n = len(point)
    area = 0
    ##
    for i in range(n):
        area += (point[i][0]*point[(i+1)%n][1] - point[i][1]*point[(i+1)%n][0])
    area *= 0.5
    ##
    print( ("CCW" if area > 0 else "CW"), "%.1f" % abs(area) )

## Main
if __name__ == "__main__":
    n = int(input())
    p = [[0]*2 for _ in range(n)]
    for i in range(0, n):
        p[i] = list(map(int, input().split()))
    solve(p);