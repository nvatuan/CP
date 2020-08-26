## python 3

t = int(input())
while t > 0:
    t -= 1
    ##
    n, m = map(int, input().split())
    print("YES\n" if min(n % m, m % n) == 0 else "NO\n")


