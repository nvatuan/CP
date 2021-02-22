_MULTITEST = False
##
def solve():
    MOD = int(1e9) + 7

    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    neg = sum(1 for x in a if x < 0)
    pos = sum(1 for x in a if x > 0)
    zero = a.count(0)
    
    ### Set lower bound for answer
    ans_is_neg = False
    if n == k:
        if zero == 0 and neg % 2 == 1:
            ans_is_neg = True
    else:
        if pos == 0:
            if zero == 0:
                if k % 2 == 1:
                    ans_is_neg = True
    
    ### Solve by window-sliding
    # set some initial vars

    #print(ans_is_neg)
    if ans_is_neg:
        prod = 1
        for i in a[n-k:n]:
            prod = (prod * i) % MOD
        print(prod)
    else:
        prod = 1
        p1 = 0; p2 = n-1;
        while k > 0:
            if k > 1 and p1 + 1 < n and 0 < p2 and a[p1] * a[p1+1] > a[p2] * a[p2-1]:
                prod = (prod * a[p1] * a[p1 + 1]) % MOD
                p1 += 2; k -= 2;
            else:
                prod = (prod * a[p2]) % MOD
                p2 -= 1; k -= 1;
        print(prod)

##
if __name__ == "__main__":
    t = (int(input()) if _MULTITEST else 1)
    for tt in range(t):
        solve()