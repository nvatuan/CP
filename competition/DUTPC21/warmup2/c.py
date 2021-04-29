for T in range(int(input())):
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    A.sort()
    A = A[::-1]

    ans = 0
    p = 0
    while k > 0 and p < n:
        k -= A[p]
        p += 1
        ans += 1
    if (k > 0): print(-1)
    else: print(ans)
