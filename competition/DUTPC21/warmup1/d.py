n = int(input())

def pow_mod(base, exp, mod):
    if exp < 0: return 1
    if exp == 0: return 1

    res = 1
    while exp > 0:
        if exp % 2 == 1: res = res * base % mod
        base = base * base % mod
        exp //= 2
    return res

print(pow_mod(3, n-1, int(1e6)+3))
