__MULTITEST = True

## solve
def solve():
    n = int(input())
    a = list(map(int, input().split()))

    nim = [1] * n
    for i in range(n-2, -1, -1):
        if nim[i+1] == 1:
            if a[i] > 1:
                nim[i] = 1
            else:
                nim[i] = 0
        else:
            nim[i] = 1

    print("First" if nim[0] == 1 else "Second")

## main
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve();