n, k = map(int, input().split())

def next_a(a):
    ls = [i for i in str(a)]
    ls.sort()
    g1 = int(''.join(ls.copy()))
    g2 = int(''.join(ls[::-1]))
    return g2-g1

a = n
for kk in range(k):
    a = next_a(a)

print(a)