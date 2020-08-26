_MULTITEST = True
## ===============

def solve():
    n = int(input())    
    s = str(input())
    
    sumBracket = 0
    dif = 0
    for i in range(n):
        sumBracket += (1 if s[i] == '(' else -1)
        dif = min(dif, sumBracket)
    
    print(abs(dif))

if __name__ == "__main__":
    t = (int(input()) if _MULTITEST else 1)
    for tt in range(t):
        solve()