A, B, X = map(int, input().split())

def check(k):
    #print(k)
    return (A * k + B * len(str(k))) <= X

L = 0
R = int(1e9)

while L < R:
    mid = (L + R + 1) // 2
    if check(mid) == True:
        L = mid
    else:
        R = mid - 1

print(L)