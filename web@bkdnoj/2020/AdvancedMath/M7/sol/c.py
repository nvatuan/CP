ERROR = 1e-9

def tri_area(a, b, c):
    x = [a[0], b[0], c[0]]
    y = [a[1], b[1], c[1]]
    return abs(x[0]*y[1] + x[1]*y[2] + x[2]*y[0] - x[0]*y[2] - x[1]*y[0] - x[2]*y[1])/2

def solve(tri, apple):
    area = tri_area(tri[0], tri[1], tri[2])
    owned_apple = 0
    ##
    for acoor in apple:
        if abs(
             tri_area(tri[0], tri[1], acoor) + tri_area(tri[1], tri[2], acoor) + tri_area(tri[2], tri[0], acoor)
             - area ) <= ERROR:
            owned_apple += 1
    ##
    print(area, owned_apple, sep = '\n')

## Main
if __name__ == "__main__":
    tri = [0] * 3
    for _ in range(0, 3):
        tri[_] = list(map(int, input().split()))
    N = int(input())
    apple = [[0]*2 for _ in range(0, N)]
    for _ in range(0, N):
        apple[_] = list(map(int, input().split()))
    solve(tri, apple)