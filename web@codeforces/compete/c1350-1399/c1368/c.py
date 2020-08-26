__MULTITEST = 0

from math import log
from math import ceil

def solve():
    n = int(input())

    SET = [[0, 0]]

    for i in range(0, n + 1):
        x = SET[-1][0]
        y = SET[-1][1]
        SET.append([x+1, y])
        SET.append([x, y+1])
        SET.append([x + 1, y + 1])
    
    print(len(SET))
    for a in SET:
        print(*a, sep = ' ')


####
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()