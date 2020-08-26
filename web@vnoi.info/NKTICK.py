## Python3
N = int(input())
t = list(map(int, input().split()))
r = list(map(int, input().split()))

r.insert(0, (1<<64) * -1)
## 
for i in range(1, N):
    r[i] -= t[i-1]

DP = [ [1<<64] * N for _ in range(0, 2) ]
DP[0][0] = t[0]
for i in range(1, N):
    DP[0][i] = min(DP[0][i-1], DP[1][i-1]) + t[i]
    DP[1][i] = DP[0][i-1] + r[i]
##
print(min(DP[0][N-1], DP[1][N-1]))

