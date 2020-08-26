from math import sqrt
from math import gcd

__MULTITEST = True
##
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    m = [0]*n

    wrong_seg = 0
    for i in range(0, n):
        if a[i] == i+1:
            m[i] = 1

    for i in range(1, n):
        if m[i-1] != m[i]:
            wrong_seg += 1
    if m.count(0) == n:
        wrong_seg = 1
    
    #print(m)

    if wrong_seg == 0:
        print(0)
    elif wrong_seg == 1:
        print(1)
    elif wrong_seg >= 2:
        print(2)

##
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()