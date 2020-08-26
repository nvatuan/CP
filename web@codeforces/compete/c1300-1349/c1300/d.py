N = int(input())

A = []
for i in range(0, N):
    a = list(map(int, input().split()))
    A.append(a)

if N & 1 != 0:
    print("No")
    exit(0)

def sentral_symm(A, N):
    midx = (A[0][0] + A[N//2][0])/2
    midy = (A[0][1] + A[N//2][1])/2

    for i in range(0, N//2 + 1):
        j = (i + (N//2)) % N
        if (A[i][0] + A[j][0])/2 != midx or (A[i][1] + A[j][1])/2 != midy:
            return False
    return True

if sentral_symm(A, N):
    print("Yes")
else:
    print("No")
