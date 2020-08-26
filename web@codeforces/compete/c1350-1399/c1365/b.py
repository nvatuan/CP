__multitest = True
## =====================
def is_sorted(a, n):
    flag = True
    for i in range(1, n):
        flag &= (a[i-1] <= a[i])
    return flag

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ##
    if b.count(0) < n and b.count(1) < n:
        print("YES")
    else:
        if is_sorted(a, n):
            print("YES")
        else:
            print("NO")
    
##
if __name__ == "__main__":
    t = (int(input()) if __multitest else 1)
    for tt in range(t):
        solve()