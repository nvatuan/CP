__MULTITEST = True

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    p1 = 0; p2 = 1;

    while a[p2] != a[p1]:
        p2 += 1
    
    check = [False]*(2*n)
    ans = []
    while True:
        ans.append(a[p1])

        check[p1] = True
        check[p2] = True

        if len(ans) == n:
            break;

        while check[p1]:
            p1 += 1

        p2 = max(p1, p2) + 1
        while a[p1] != a[p2]:
            p2 += 1
    print(*ans)

## 
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()