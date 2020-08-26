def solve():
    N = int(input())
    A = list(map(int, input().split()))

    odd = evn = False
    Sum = 0
    for a in A:
        Sum += a
        if a % 2 == 0:
            evn = True
        else:
            odd = True
    
    return (odd and evn) or (Sum % 2 == 1)

T = int(input())
while T > 0:
    T -= 1
    print("YES\n" if solve() else "NO\n")
