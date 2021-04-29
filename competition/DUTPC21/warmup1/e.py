n, m, a, b = map(int, input().strip().split())
a -= 1
b -= 1

def one(n, m, a, b):
    rs = (n + m - 1) // m - 1

    if a // m == b // m: return True
    if (a%m) == 0 and (b+1)%m == 0: return True
    if (a%m) == 0 and (b==n-1): return True
    return False
    

def two(n, m, a, b):
    rs = (n + m - 1) // m - 1

    if (b//m) - (a//m) == 1: return True 
    if (a%m) > 0 and (b+1)%m==0: return True
    if (a%m) == 0 and (b+1)%m != 0: return True
    if (a%m) > 0 and (b == n-1): return True
    if (a%m) == ((b+1)%m): return True
    return False

if one(n,m,a,b): print(1)
elif two(n,m,a,b): print(2)
else: print(3)
