def so(l, r):
    return ((r+1)//2)**2 - ((l+1)//2)**2

def solve():
    l, r = map(int, input().split())
    print(so(l-1, r))

if __name__ == "__main__":
    # t = int(input())
    # for tt in range(t):
    solve()