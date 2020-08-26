A = list(map(int, input().split()))

A.sort()
if A[0]+A[1]+A[2] != A[1]*3 and (A[0] == A[1] or A[1] == A[2]):
    print("Yes\n")
else:
    print("No\n")
