def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ## --
    possibleFlag = True
    posBumpFlag = False
    negBumpFlag = False
    for i in range(0, n):
        if a[i] != b[i]:
            if a[i] < b[i] and posBumpFlag == False:
                possibleFlag = False
            if a[i] > b[i] and negBumpFlag == False:
                possibleFlag = False
        if a[i] > 0:
            posBumpFlag = True
        elif a[i] < 0:
            negBumpFlag = True

    print("YES" if possibleFlag else "NO")

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t -= 1
        solve()