def solve():
    n, m = map(int, input().split())
    ##
    A    = list(map(int, input().split()))
    S = sum(A)
    print( min(S, m) )

T = int(input())
while T > 0:
    T -= 1
    solve()

