n, d = map(int, input().split())

points = []
for i in range(n):
  x, y = map(int, input().split())
  points.append([x, y])

d = d*d
def dist(x, y):
    return x*x + y*y

ans = sum([1 for p in points if dist(p[0], p[1]) <= d])
print(ans)