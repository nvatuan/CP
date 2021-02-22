n = int(input())
a = list(map(int, input().split()))

d = {}
for x in a:
    if d.get(x, 0) == 0:
        d[x] = 1
    else:
        print("NO")
        exit(0)
print("YES")

