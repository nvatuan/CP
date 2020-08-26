__MULTITEST = True

## solve
def solve():
    s = str(input())

    play = {}
    play['R'] = 'P'
    play['P'] = 'S'
    play['S'] = 'R'

    maxChar = 'P'
    for p in ['R', 'S']:
        if s.count(p) > s.count(maxChar):
            maxChar = p

    tac = play[maxChar] * len(s)
    print(tac)


## main
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve();