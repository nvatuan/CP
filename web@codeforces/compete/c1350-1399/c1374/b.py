_MULTITEST = True
## ===============

def solve():
    n = int(input())    
    factor3 = 0
    factor2 = 0
    while True:
        if (n % 3 == 0):
            factor3 += 1
            n /= 3
            continue
        if (n % 2 == 0):
            factor2 += 1
            n /= 2
            continue
        if n == 1:
            break
        else:
            print(-1)
            return
    print((factor3 - factor2 + factor3) if factor3 >= factor2 else -1)

if __name__ == "__main__":
    t = (int(input()) if _MULTITEST else 1)
    for tt in range(t):
        solve()