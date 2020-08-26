## Python3
# http://vnoi.info/problems/VSTEPS/

def solve():
    n, k = map(int, input().split())
    ###
    broke = [0] * (n+5)
    dp    = [0] * (n+5)
    #
    if k != 0:
        broken = list(map(int, input().split()))
        for br in broken:
            broke[br] = True
    #
    dp[1] = (0 if broke[1] else 1)
    for i in range(1, n+1):
        for j in range(i+1, i+3):
            dp[j] += (0 if broke[j] else dp[i])
            dp[j] %= 14062008
    #
    print(dp[n])

## ==
solve()
