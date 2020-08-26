__MULTITEST = True

def solve():
    x = list(map(int, input().split()))
    x.sort(reverse = True)
    if x.count(x[0]) == 2:
        print("YES")
        print(x[0], x[2], x[2])
    elif x.count(x[0]) == 3:
        print("YES")
        print(*x)
    else:
        print("NO")
### 
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()