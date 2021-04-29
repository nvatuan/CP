def ccw(a, b, c):
    return (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]) 

A = list(map(int, input().strip().split()))
B = list(map(int, input().strip().split()))
C = list(map(int, input().strip().split()))

val = ccw(A, B, C)
if val < 0: print("RIGHT")
if val == 0: print("TOWARDS")
if val > 0: print("LEFT")
