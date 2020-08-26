__MULTITEST = True

## solve
def solve():
    n = int(input())
    a = list(map(int, input().split()))

    minL = [x for x in range(n)]
    minR = [x for x in range(n)]

    for i in range(1, n):
        if (a[minL[i]] > a[minL[i-1]]):
            minL[i] = minL[i-1]
    
    for i in range(n-2, -1, -1):
        if a[minR[i]] > a[minR[i+1]]:
            minR[i] = minR[i+1]

    #print(minL)
    #print(minR)

    for i in range(1, n-1):
        if minL[i] != i and minR[i] != i:
            print("YES")
            print(minL[i] + 1, i + 1, minR[i] + 1)
            return
    print("NO")

## main
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve();