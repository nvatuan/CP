A = int(input())
B = int(input())
M = int(input())

def powMod(base, exp):
    if exp == 0:
        return 1
    if exp == 1:
        return base % M
    if exp % 2 == 1:
        return powMod(base * base, exp//2) % M * base % M 
    else:
        return powMod(base * base, exp//2) % M

A %= M
print(powMod(A, B))

