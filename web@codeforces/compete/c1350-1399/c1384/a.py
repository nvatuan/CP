__MULTITEST = True

## =========================== SOLUTION ==============================
def solve():
    n = int(input())
    a = list(map(int, input().split()))

    sample = 'abcdefghijklmnopqrstuvwxyz' * 1
    ans = [sample] * (n+1)

    for i in range(n):
        s = ans[i][a[i]+1:] + ans[i][a[i]];
        ans[i+1] = ans[i][:a[i]] + s;

    print(*ans, sep = '\n')


## ===================================================================
if __name__ == '__main__':
    test = (int(input()) if __MULTITEST else 1)
    for tt in range(test):
        solve()