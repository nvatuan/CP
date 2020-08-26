def solve():
    n = int(input())
    st = str(input())
    minst = st
    #
    ans = 0
    minchar = chr(ord('z') + 1)
    for i in range(0, n + 1):
        newst = st[i:] + str(st[0:i])[::(-1 if (n-i+1) % 2 == 0 else 1)]
        if newst < minst:
            minst = newst
            ans = i
    print(minst)
    print(ans+1)

T = int(input())
while T > 0:
    T -= 1
    solve()

