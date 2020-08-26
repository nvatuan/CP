## Python3
N = int(input())
A = list(map(int, input().split()))

dp = [1] * N
for i in range(0, N):
    for j in range(i, -1, -1):
        if A[j] < A[i]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))

