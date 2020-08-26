## python 3

MOD = 998244353
def inv(x, y, p = 1, q = 0, r = 0, s = 1):
    return (p % MOD + MOD) % MOD if y == 0 else inv(y, x%y, r, s, p - r*(x//y), q - s*(x//y))

_facto = [0] * (2*(10**5) + 1)

def precompute():
    _facto[0] = 1
    for i in range(1, len(_facto)):
        _facto[i] = (_facto[i-1] * i) % MOD

def C(k, n):
    if k > n:
        return 0
    if _facto[0] == 0:
        precompute()
    ##
    return _facto[n] * inv(_facto[k], MOD) % MOD * inv(_facto[n-k], MOD) % MOD

## 
n, m = map(int, input().split())
result = 0
for i in range(2, n): # [2, n-1]
    result += (m-1)*( C(i-1, (m-1)) * C(n-i-1, (m-i)) ) % MOD
    result %= MOD
print(result)

