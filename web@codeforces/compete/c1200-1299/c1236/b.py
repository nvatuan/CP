n, m = map(int, input().split())

MOD = int(1e9 + 7)

def powmod(b, e):
    if e == 0:
        return 1
    elif e == 1:
        return b % MOD
    elif e % 2 == 1:
        return 


