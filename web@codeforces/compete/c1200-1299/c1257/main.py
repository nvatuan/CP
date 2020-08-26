def solve():
    n = int(input())
    a = list(map(int, input().split()))

    h = {}
    ## --
    ans = n*2
    #
    idx = 0
    for x in a:
        idx += 1
        if h.get(x) == None:
            h[x] = idx
        else:
            ans = min(idx - h[x] + 1, ans)
            h[x] = idx
    ## --
    if ans == n*2:
        print("-1")
    else:
        print(ans)

t = int(input())

while t > 0:
    t -= 1
    ## ==
    solve()

