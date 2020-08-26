## python 3

t = int(input())
while t > 0:
    t -= 1
    ##
    n = int(input())
    a = list(map(int, input().split()))
    a.sort(reverse = True)
    print(*a)

