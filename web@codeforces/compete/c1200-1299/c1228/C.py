x, n = map(int, input().split())

def prime(x):
    p = 2
    P = []
    while p*p <= x:
        if x % p == 0:
            P.append(p)
            while x % p == 0 and x != 0:
                x = int(x // p)
        p += 1

    if x != 1:
        P.append(x)

    return P

def fact(n, x):
    res = 0
    while n > 0:
        res += int( n // x )
        n = int( n // x )
    return res

def expMod(b, e, m):
    if e == 0:
        return 1
    elif e == 1:
        return (b % m)
    elif e % 2 == 0:
        return expMod(b*b%m, int(e//2), m)
    elif e % 2 == 1:
        return expMod(b*b%m, int(e//2), m) * b % m

# ========================

result = 1
P = prime(x)

m = int(1e9) + 7

for p in P:
    pwr = fact(n, p)
    q = int( pwr // m )
    r = int( pwr % m )

    result *= expMod(p, q+r, m)
    result %= m

print(result)