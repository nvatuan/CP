from string import ascii_letters as alpha

def solve():
    n, a, b = map(int, input().split())
    ## --
    ans = alpha[0:b]
    ans = (ans[0] * (a - b)) + ans
    while len(ans) < n:
        ans += ans
    print(ans[0:n])

## --
t = int(input())
while t > 0:
    t -= 1
    solve()