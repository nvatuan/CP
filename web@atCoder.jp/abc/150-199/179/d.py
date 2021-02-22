N, K = map(int, input().split())
Range = [None] * K

for i in range(K):
    Range[i] = list(map(int, input().split()))

sweep = {1: 1}
M = 998244353

value = 0
for cell in range(1, N+1):
    value += sweep.get(cell, 0)
    value = (value + M) % M
    for r in range(K):
        sweep[cell + Range[r][0]] = (sweep.get(cell + Range[r][0], 0) + value + M) % M
        sweep[cell + Range[r][1] + 1] = (sweep.get(cell + Range[r][1] + 1, 0) - value + M) % M

print(sweep.get(N, 0))