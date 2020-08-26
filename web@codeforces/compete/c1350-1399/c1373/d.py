__MULTITEST = True

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    l = 0; r = -1;

    da = []
    db = []

    for i in range(1, n, 2):
        da.append(a[i] - a[i-1])
    
    glMax = 0
    la = 0; ra = -1;
    curMax = 0
    lc = 0; rc = -1;

    for i in range(len(da)):
        curMax += da[i];
        if curMax > 0:
            rc = i;
            if curMax > glMax:
                glMax = curMax
                la, ra = lc, rc;
        else:
            curMax = 0;
            lc = i + 1;

    db = []
    for i in range(2, n, 2):
        db.append(a[i-1] - a[i])

    glMaxB = 0
    lB = 0; rB = -1;
    curMax = 0
    lc = 0; rc = -1;

    for i in range(len(db)):
        curMax += db[i];
        if curMax > 0:
            rc = i;
            if curMax > glMaxB:
                glMaxB = curMax
                lB, rB = lc, rc;
        else:
            curMax = 0;
            lc = i + 1;
    
    if glMax < glMaxB:
        l = lB*2 + 1; r = rB*2 + 2;
    else:
        l = la*2; r = ra*2 + 1;

    a1 = a[:l]
    a2 = a[l:r+1]; a2.reverse()
    a3 = a[r+1:]
    #print(a1, a2, a3)
    a = a1 + a2 + a3
    #print(a)
    print(sum([a[i] for i in range(len(a)) if i % 2 == 0]))


# main
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()