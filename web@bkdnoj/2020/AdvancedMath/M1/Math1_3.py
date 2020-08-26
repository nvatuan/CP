def present(n):
    if n == 1:
        return 1
    if n == 2:
        return 6
    return 6*(n-1) - (n-2) + 4*( (n-1)*(n-2)/2 )

t = int(raw_input())

while (t > 0):
    t -= 1
    n = int(raw_input())
    print( present(n) )

