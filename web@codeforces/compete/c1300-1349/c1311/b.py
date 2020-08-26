def solve():
    n, m = map(int, input().split())
    a    = list(map(int, input().split()))
    p    = list(map(int, input().split()))
    ## ------
    a.append(999)
    a.append(999)
    a.append(999)
    a.append(999)
    #
    asort = a.copy()
    asort.sort()
    ##
    D    = [ [0] * 110 for _ in range(0, 110) ]
    for x in p:
        D[x-1][x] = True
    ##
    seg_unsort = []
    seg_sort   = []
    connect = False
    for i in range(0, n+1):
        # print(i," | ", seg_unsort, " | ", seg_sort)
        if D[i][i+1] == True:
            if connect == True:
                seg_unsort.append(a[i+1])
                seg_sort.append(asort[i+1])
            else:
                connect = True
                seg_unsort.append(a[i])
                seg_unsort.append(a[i+1])
                ##
                seg_sort.append(asort[i])
                seg_sort.append(asort[i+1])
        else:
            if(connect == True):
                connect = False
                ##
                seg_unsort.sort()
                seg_sort.sort()
                if seg_unsort != seg_sort:
                    print("NO")
                    return
                seg_unsort = []
                seg_sort = []
            else:
                if a[i] != asort[i]:
                    # print("Discrepancy: ", a[i], asort[i])
                    print("NO")
                    return
    ##
    print("YES")

T = int(input())
while T > 0:
    T -= 1
    solve()

