from math import sqrt, ceil

n = int(input())
s = set()

for a in range(2, int(sqrt(n))+1):
    expo = a
    for b in range(2, 1001):
        expo *= a 
        if expo <= n:
            s.add(expo)
        else:
            break

print(n-len(s))
