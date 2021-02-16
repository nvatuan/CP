h, w, n, m = map(int, input().split())
grid = [[0] * w for _ in range(h)]

BLOCK = -2

hlist = [[] for _ in range(h)]
wlist = [[] for _ in range(w)]

for i in range(n):
    a, b = map(int, input().split())
    hlist[a-1].append(b-1)
    wlist[b-1].append(a-1)
for i in range(h):
    hlist[i].sort()
for i in range(w):
    wlist[i].sort()

for i in range(m):
    a, b = map(int, input().split())
    grid[a-1][b-1] = BLOCK

# sweep horizontally
ans = 0
for i in range(h):
    ptr = -1
    for b in hlist[i]:
        if ptr < b:
            ptr = b
            while 0 <= ptr and grid[i][ptr] != BLOCK:
                ans += not grid[i][ptr]
                grid[i][ptr] = 1
                ptr -= 1
            ptr = b
            while ptr < w and grid[i][ptr] != BLOCK:
                ans += not grid[i][ptr]
                grid[i][ptr] = 1
                ptr += 1

# sweep vertically
for j in range(w):
    ptr = -1
    for b in wlist[j]:
        if ptr < b:
            ptr = b
            while 0 <= ptr and grid[ptr][j] != BLOCK:
                ans += not grid[ptr][j]
                grid[ptr][j] = 1
                ptr -= 1
            ptr = b
            while ptr < h and grid[ptr][j] != BLOCK:
                ans += not grid[ptr][j]
                grid[ptr][j] = 1
                ptr += 1

print(ans)