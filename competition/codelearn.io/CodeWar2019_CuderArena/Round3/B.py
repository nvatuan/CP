def numberOfZeroDigits(n):
    k = 1
    result = 0
    # --
    while True:
        s1 = (n - (5**k))//(5**k)
        result += (((s1*(s1+1))//2)*(5**k)) + ((n % (5**k) + 1) * (n//(5**k)))
        k += 1
        if 5**k > n:
            return result