from random import randint 

M, N, P = 10, 100, 10000

print(M, N, P, sep = ' ')

arr = [i for i in range(N)]
for i in range(M):
    chose = randint(0, len(arr) - 1)
    print(arr[chose], randint(1, int(1e9)), sep = ' ')
    arr.pop(chose)
for i in range(N):
    arr = [randint(1, int(1e4)) for j in range(N)]
    arr[i] = 0
    print(*arr)
