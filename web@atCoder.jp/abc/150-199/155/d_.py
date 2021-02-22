N, K = map(int, input().split())
A    = list(map(int, input().split()))

prd = []
for i in range(0, N):
    for j in range(i+1, N):
        prd.append(A[i]*A[j])
prd.sort()
print(prd)
print(prd[K])
