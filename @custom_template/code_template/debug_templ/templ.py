__MULTITEST = True

## =========================== SOLUTION ==============================
def solve():
    n = int(input())
    print(n)

## ===================================================================
if __name__ == '__main__':
    test = (int(input()) if __MULTITEST else 1)
    for tt in range(test):
        solve()