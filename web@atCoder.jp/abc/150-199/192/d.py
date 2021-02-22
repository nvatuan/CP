x = str(input())
m = int(input())

mx = max([int(i) for i in x]) + 1

def test(num, base, threshold):
    # convert from base D -> base 10, threshold = M
    val = 0
    expo = 1
    for c in num[::-1]:
        val += expo*int(c)
        expo *= base
        if val > threshold: return False
    
    return True

if len(x) == 1:
    if (int(x) <= m): print(1)
    else: print(0)
    exit(0)

if len(x) == 2:
    b = (m - int(x[-1])) // int(x[-2])
    print(max(0, b - mx + 1))
    exit(0)

if len(x) == 3:
    a1, b1, c1 = map(int, x[:])
    delta = b1**2 - 4*a1*(c1 - m)
    if delta <= 0
        print(0)
    else:
        from math import sqrt
        b = (-b1 + int(sqrt(delta)))//(2*a1)
        print(max(0, b-mx+1))
    exit(0)

ans = 0
for b in range(mx, (int)(1e18)):
    if test(x, b, m):
        ans += 1
    else:
        break
print(ans)