n, W = map(int, input().split())

INF = int(1e16)

dp = [[INF] * (int(1e5) + 1) for _ in range(n + 1)]
# dp[i][v] minimum total weight of the first i items that sum value is exactly v

dp[0][0] = 0

for i in range(1, n + 1):
    weight, value = map(int, input().split())
    for v in range(int(1e5) + 1):
        dp[i][v] = min(dp[i-1][v], dp[i][v])
        if v >= value:
            dp[i][v] = min(dp[i][v], dp[i-1][v-value] + weight)

#print(*dp, sep = '\n')

for v in range(int(1e5), -1, -1):
    if dp[n][v] <= W:
        print(v)
        break