_MULTITEST = False
##
def solve():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()
    print(sum(
        a[n - (k//2) - 1] for k in range(1, n)
    ))

##
if __name__ == "__main__":
    t = (int(input()) if _MULTITEST else 1)
    for tt in range(t):
        solve()