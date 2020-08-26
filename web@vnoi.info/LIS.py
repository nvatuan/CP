## Python3
# http://vnoi.info/problems/LIS/

n = int(input())
A = list(map(int, input().split()))

lis = []

def lower_bound(x):
    global lis
    ###
    L, R = 0, len(lis) - 1
    while L < R:
        mid = (L + R)//2
        if lis[mid] < x:
            L = mid + 1
        else:
            R = mid
    return L

def LIS(x):
    global lis
    ###
    if len(lis) < 1:
        lis.append(x)
    else:
        if x < lis[0]:
            lis[0] = x
        elif x > lis[-1]:
            lis.append(x)
        else:
            lis[ (lower_bound(x)) ] = x
    ###
    return len(lis)

for a in A:
    LIS(a)
print( len(lis) )

