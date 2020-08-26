def solve():
    n = int(input())
    if n == 1:
        print(-1)
    else:
        print( '5'*(n-1) + '8' )

t = int(input())
while t > 0:
   t -= 1
   solve();
