N = int(input())
lst = []
res = 0 
for i in range(N):
    a,b = map(int,input().split())
    lst.append([a,b])
    res += (b-a+1)*(a+b)//2
print(res)


