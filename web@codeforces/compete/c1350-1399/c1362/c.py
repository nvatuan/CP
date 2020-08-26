__multitest__ = True

def solve():
    n = int(input())
    ans = 0

    for b in range(0, 64):
        if (1 << b) > n:
            break
        else:
            ans += (n // (1 << b))

    print(ans)

##
if __name__ == "__main__":
    t = (1 if not __multitest__ else int(input()))
    for tt in range(t):
        solve();
