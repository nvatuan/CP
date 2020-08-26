__MULTITEST = 0

from math import log
from math import ceil
from math import floor

def solve():
    k = int(input())


    chara = 1
    amount = 0

    string = "codeforces"
    ansCount = int(1e18)
    ans = ""

    while chara <= 10000:
        for i in range(1, 11):
            amount = chara**i
            if amount >= k:
                ansCandidate = ""
                for j in range(0, i):
                    ansCandidate += (string[j] * chara)
                for j in range(i, 10):
                    ansCandidate += (string[j])
                if len(ansCandidate) < ansCount:
                    ans = ansCandidate
                    ansCount = len(ans)
        chara += 1
        ##
    print(ans)

####
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()