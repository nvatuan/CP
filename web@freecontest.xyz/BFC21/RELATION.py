n, k = map(int, input().split())

ans = 0

def trip(x):
    return x**3;

## mod == 0
d = n // k
ans += trip(d)

## mod == k/2
if k % 2 == 0:
    d = n // k + (1 if n % k >= (k//2) else 0)
    ans += trip(d)

print(ans)