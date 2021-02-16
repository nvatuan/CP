def c3(n):
    return n*(n-1)*(n-2)//6

def c2(n):
    return n*(n-1)//2

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    h = {}
    for x in a:
        h[x] = h.get(x, 0) + 1
    
    ans = 0
    for k in h.keys():
        cnt0 = h.get(k, 0)
        cnt1 = h.get(k+1, 0)
        cnt2 = h.get(k+2, 0)

        ans += c3(cnt0)
        ans += c2(cnt0) * (cnt1 + cnt2)
        ans += cnt0 * c2(cnt1)
        ans += cnt0 * cnt1 * cnt2
        ans += cnt0 * c2(cnt2)
    
    print(ans)

if __name__ == "__main__":
    t = int(input())
    for tt in range(t):
        solve()