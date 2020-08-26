__multitest = False
## =====================
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ##
    da = {}
    db = {}
    for i in range(n):
        da[a[i]] = i
        db[b[i]] = i
    ##
    dv = {}
    for x in range(n):
        dv[x + 1] = (da[x + 1] - db[x + 1] + n) % n
    ##
    da = {}
    ans = 0
    for k in dv.keys():
        da[dv[k]] = da.get(dv[k], 0) + 1
    print(max(da.values()))

    
##
if __name__ == "__main__":
    t = (int(input()) if __multitest else 1)
    for tt in range(t):
        solve()