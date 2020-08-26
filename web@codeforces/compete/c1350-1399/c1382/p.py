__MULTITEST = True

## solve

def solve():
    n = int(input())
    p = list(map(int, input().split()))

    p.append(int(1e9))

    ##
    seg = [0]*(2*n)
    cnt = 1
    _max = p[0]
    ptr = 1
    while ptr <= 2*n:
        if p[ptr] > _max:
            seg[ptr-1] = cnt;
            _max = p[ptr]; cnt = 1;
        else:
            cnt += 1;
        ptr += 1
    ##
    #print(seg)

    items = [x for x in seg if x > 0]
    dp = [[0] * (len(items) + 5) for _ in range(n+5)]

    #print(items)

    dp[0][0] = 1
    for i in range(len(items)):
        dp[i+1][0] = 1

    for i in range(len(items)):
        for w in range(1, n+1):
            if w >= items[i]:
                dp[i+1][w] = max(dp[i+1][w], dp[i][w-items[i]])
    
    #print(*dp, sep ='\n')

    for i in range(len(items)):
        if dp[i+1][n] == 1:
            print("YES")
            return
    print("NO")

## main
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve();