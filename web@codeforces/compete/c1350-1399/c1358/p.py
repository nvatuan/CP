def solve():
    x1, y1, x2, y2 = map(int, input().split())
    deltax = x2-x1
    deltay = y2-y1
    print(deltax*deltay + 1)

if __name__ == "__main__":
    t = int(input())
    for tt in range(t):
        solve()