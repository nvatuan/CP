__MULTITEST = True

def solve():
    a, b, c = map(int, input().split())

    if a*b < c:
        print(b, -1)
    elif a*b > c:
        if a < c:
            print(1, b)
        else:
            print(-1, b)
    else:
        if a < c:
            print(1, -1)
        else:
            print(-1, -1)

# main
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()