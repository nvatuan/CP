N = int(input())
lst = []
check = 0
for i in range(N):
    a,b = map(int,input().split())
    lst.append([a,b])
for i in range(N-2):
    x0, y0 = lst[i][0], lst[i][1]
    a, b = x0, -y0
    for j in range(i+1, N-1):
        x1, y1 = lst[j][0], lst[j][1]
        x1 -= a
        y1 -= b
        for k in range(j+1,N):
            x2, y2 = lst[k][0], lst[k][1]
            x2 -= a 
            y2 -= b
            if y2*x1 == y1*x2: check = 1
if check == 1: print('Yes')
else: print('No')



