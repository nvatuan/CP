def f(x):
    return x**3

def solve():
    k = int(input())

    l, r = 0, 10**7
    while l <= r:
        mid = l + (r - l)//2
        if f(mid) == k:
            print('YES') 
            return None
        if f(mid) < k: l = mid + 1
        else: r = mid - 1
    print('NO')

t = int(input())
for tt in range(t):
    solve()