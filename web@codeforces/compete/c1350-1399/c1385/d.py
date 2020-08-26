__MULTITEST = True;

def fix(sHalf, sNext, c):
    cost = len(sHalf) - sHalf.count(c)
    if len(sNext) == 1:
        cost += (1 if sNext[0] != chr(ord(c) + 1) else 0)
    else:
        mid = len(sNext)//2
        cost += min(
            fix(sNext[:mid], sNext[mid:], chr(ord(c) + 1)),
            fix(sNext[mid:], sNext[:mid], chr(ord(c) + 1))
        )
    
    return cost

def costCal(s):
    if len(s) == 1:
        return 1 if s[0] != 'a' else 0
    mid = len(s)//2
    cost1 = fix(s[:mid], s[mid:], 'a')
    cost2 = fix(s[mid:], s[:mid], 'a')
    return min(cost1, cost2)

def solve():
    n = int(input())
    s = str(input())
    print(costCal(s))

## 
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()