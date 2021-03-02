n = int(input())

INF = int(2e9)
ans = INF

for i in range(n):
    ls = list(map(int, input().split()))
    if ls[0] >= ls[2]:
        pass
    else:
        ans = min(ans, ls[1])

print(-1 if ans == INF else ans)
