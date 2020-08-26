import sys

global N, M
global edgeList

global longestPathFrom

def dfs(x):
    if longestPathFrom[x] == -1:
        # get
        longest = -1
        for nextNode in edgeList[x]:
            longest = max(longest, dfs(nextNode))
        # set
        if longest == -1:
            longestPathFrom[x] = 0
        else:
            longestPathFrom[x] = longest + 1
    # -- longest path from x has been calculated
    return longestPathFrom[x]

# -- main
if __name__ == '__main__':
    # -- 
    sys.setrecursionlimit(1000001)

    # -- input
    N, M = map(int, input().split())
    edgeList = [[] for node in range(N)]

    for i in range(M):
        x, y = map(int, input().split())
        x -= 1; y -= 1;
        edgeList[x].append(y)

    # -- process
    longestPathFrom = [-1] * N

    for node in range(N):
        if longestPathFrom[node] == -1:
            dfs(node)

    # -- output
    print(max(longestPathFrom))