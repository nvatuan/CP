n = int(input())
h = list(map(int, input().split()))

dp = [10**10] * n
dp[0] = 0

for i in range(n):
    if i > 0:
        dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i-1]))
    if i > 1:
        dp[i] = min(dp[i], dp[i-2] + +abs(h[i] - h[i-2]))

print(dp[n-1])
