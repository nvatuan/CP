_MULTITEST = True
## ===============

def solve():
    n, k = map(int, input().split());
    a = list(map(int, input().split()));
    
    r = [ (k - (x % k)) % k for x in a]
    r.sort()

    increment = [0] * n
    for i in range(1, n):
        if r[i] == 0:
            continue
        if r[i-1] == r[i]:
            increment[i] = increment[i-1] + k
    
    for i in range(n):
        r[i] += increment[i]
    r.sort();

    op = 0
    x = 0
    for i in range(n):
        if r[i] != 0:
            if x < r[i]:
                op += (r[i] - x)
                x = r[i]
            op += 1
            x += 1
    print(op)

if __name__ == "__main__":
    t = (int(input()) if _MULTITEST else 1)
    for tt in range(t):
        solve()