sa, sb  = input().split()
a,  b   = map(int, input().split())
sc      = input().strip()
if sc == sa:
    print(a-1, b, sep = ' ')
else:
    print(a, b-1, sep = ' ')
