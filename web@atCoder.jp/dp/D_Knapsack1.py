N, W = map(int, input().split())
item = [[0]*2 for _ in range(N+1)]

for i in range(1, N+1):
    item[i][0], item[i][1] = map(int, input().split())

DP = [[0]*(W+1) for _ in range(N+1)]

for i in range(1, N+1):
    for w in range(0, W+1):
        DP[i][w] = DP[i-1][w]
        if w >= item[i][0]:
            DP[i][w] = max(DP[i][w], DP[i-1][w - item[i][0]] + item[i][1])

print(DP[N][W])