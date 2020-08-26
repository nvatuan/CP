n, k = map(int, input().split())
p    = list(map(int, input().split()))

L = 0
R = k

def expected(pi):
    return (pi+1)/2

value = 0.0
sans  = 0.0
for i in range(0, k):
    sans += expected(p[i])
ans   = sans

while R < n:
    sans -= expected(p[L])
    sans += expected(p[R])

    ans = max(ans, sans)

    L += 1
    R += 1
print("%.7f" % ans)
