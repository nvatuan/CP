def solve():
    N = int(input())
    d = 10**9
    
    ans = 0

    while d > 0:
        while N >= d:
            ans += d
            N = (N - d) + (d // 10)
        d //= 10
    print(ans)


T = int(input())
while T > 0:
    T -= 1
    solve()
