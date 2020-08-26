__MULTITEST = True

def solve():
    s = str(input())
    n = len(s)
    d = [0] * (n+1)

    for i in range(1, n+1):
        if s[i-1] == '+':
            d[i] = d[i-1] + 1
        else:
            d[i] = d[i-1] - 1

    ans = 0
    neomin = 0
    #print(d)
    for i in range(1, n+1):
        if neomin > d[i]:
            neomin = d[i]
            ans += i
    ans += n
    print(ans)

# main
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()