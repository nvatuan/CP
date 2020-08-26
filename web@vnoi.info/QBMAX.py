## Python3
# http://vnoi.info/problems/QBMAX/

m, n = map(int, input().split())
M    = [ [0]*(n+2) for _ in range(0, m+2) ]

for i in range(1, m+1):
    M[i][1:(n+1)] = map(int, input().split())

DP   = [ [-1 * (10**9)]*(n+2) for _ in range(0, m+2) ]

for j in range(1, m+1):
    DP[j][1] = M[j][1]

for j in range(2, n+1):
    for i in range(1, m+1):
        #DP[i][j] = DP[i-1][j-1] + M[i][j]
        for d in range(-1, 2):
            DP[i][j] = max(DP[i][j], DP[i+d][j-1] + M[i][j])

#for i in range(1, m+1):
#    print(*DP[i])

print(max([DP[i][n] for i in range(1, m+1)]))

