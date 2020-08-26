n = int(input())
a = list(map(int, input().split()))

a.append(0); a.append(0);
inf = int(1e9)
dp = [inf]*(n+3)
dp[0] = 0

for i in range(n):
  dp[i+1] = min(dp[i+1], dp[i] + abs(a[i+1] - a[i]))
  dp[i+2] = min(dp[i+2], dp[i] + abs(a[i+2] - a[i]))

print(dp[n-1])
