m, n = map(int, input().split())

A    = [ [0] * n for _ in range(0, m) ]
for i in range(0, m):
    A[i] = list(map(int, input().split()))

A.insert(0, [0] * n)
A.append( [0] * n )

DP   = [ [-1000000] * n for _ in range(0, len(A)) ]
for i in range(1, m+1):
    DP[i][0] = A[i][0]

for j in range(1, n):
    for i in range(1, m+1):
        for f in range(i-1, i+2):
            #print("i = %d | j = %d | f = %d" % (i, j, f))
            DP[i][j] = max(DP[i][j], DP[f][j-1] + A[i][j])


M = -1000000
for a in DP:
    #print(a)
    M = max(M, a[-1])
print(M)
