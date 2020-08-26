def solve():
    n = int(input())
    n -= 2
    print(n - (n//2))
## --
t = int(input())
while t > 0:
    t -= 1
    solve()