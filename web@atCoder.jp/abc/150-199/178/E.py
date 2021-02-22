N = int(input())
p = [[None] for i in range(N)]

for i in range(N):
    p[i] = list(map(int, input().split()))

p.sort()
#print(p)

INFINITE = 5 * 10**9
maxUp = {}
minDown = {}

for i in range(1, N):
    maxUp[i] = max(maxUp.get(i-1, -INFINITE), p[i-1][1] - p[i-1][0])
for i in range(1, N):
    minDown[i] = min(minDown.get(i-1, INFINITE), p[i-1][0] + p[i-1][1])

#print(maxUp)
#print(minDown)

ans = -INFINITE
for i in range(1, N):
    ans = max(ans, 
        p[i][0] - p[i][1] + maxUp.get(i, -INFINITE)
    )
    ans = max(ans, 
        p[i][0] + p[i][1] - minDown.get(i, INFINITE)
    )
print(ans)