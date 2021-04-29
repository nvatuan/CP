for tt in range(int(input())):
    x = int(input())
    odd, even = 0, 0
    isOdd = True
    magnitude = 1
    while x > 0:
        if isOdd:
            odd += (x % 2) * magnitude
        else:
            even += (x % 2) * magnitude
        isOdd ^= True
        x //= 2
        magnitude *= 2
    print(abs(odd-even))
