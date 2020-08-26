__MULTITEST = True

## solve

def solve():
    n = int(input())
    a = [int(d) for d in str(input())]
    b = [int(d) for d in str(input())]

    order = []
    inver = []
    p1 = 0; p2 = n-1;
    turn = 0;
    while p1 <= p2:
        if turn == 0:
            order.append(p1)
            inver.append(turn)
            p1 += 1; turn ^= 1;
        else:
            order.append(p2)
            inver.append(turn)
            p2 -= 1; turn ^= 1;

    op = []
    i = 0
    while i < n:
        if a[order[i]] ^ inver[i] == b[n - i - 1]:
            op.append(1)
            a[order[i]] ^= 1
        else:
            op.append(n - i)
            i += 1

    #print(a)
    #print(b)

    print(len(op), end = ' ')
    for x in op:
        print(x, end = ' ')
    print('')


## main
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve();