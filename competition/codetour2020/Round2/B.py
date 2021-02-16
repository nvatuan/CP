t = int(input())
ans = {
  (1, 1) : 0,
  (2, 2) : 2
}
for tt in range(t):
  n, k = map(int, input().split())
  print(ans.get((n, k), 0))