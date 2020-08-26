def removedDigit(n, s, k):
    S = ''
    for i in range(1, n+1):
        S = S + str(i)
    #
    for c in S:
        for cc in s:
            if c == str(cc):
                k -= 1
            if k == 0:
                return cc
    return -1