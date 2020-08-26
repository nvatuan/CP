def _ord(c):
    return ord(c) - 97

def solve():
    n, m = map(int, input().split())
    s    = str(input())
    err  = list(map(int, input().split()))
    ##
    Press = [0]*(n + 1)
    for e in err:
        Press[e-1] += 1
    ##
    Press[n] = 1
    for i in range(n-1, -1, -1):
        Press[i] += Press[i+1]
    # print(Press)
    ##
    alphastroke = [0]*26
    for i in range(0, n):
        alphastroke[_ord(s[i])] += Press[i]
    print(*alphastroke)


T = int(input())
while T > 0:
    T -= 1
    solve()

