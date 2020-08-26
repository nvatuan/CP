__MULTITEST = False
##
def solve():
    n, d = map(int, input().split())
    x = []
    a = []
    b = []
    for i in range(n):
        X, A, B = map(int, input().split())
        

if __name__ == "__main__":
    t = int(input()) if __MULTITEST else 1
    for tt in range(t):
        solve()