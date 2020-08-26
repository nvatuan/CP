def solve():
    a, b = map(int, input().split())
    ##
    if a == b:
        print(0)
    elif a < b:
        print( 1 if ((b - a) % 2 == 1) else 2)
    elif a > b:
        print( 1 if ((a - b) % 2 == 0) else 2)

T = int(input())
while T > 0:
    T -= 1
    solve()

