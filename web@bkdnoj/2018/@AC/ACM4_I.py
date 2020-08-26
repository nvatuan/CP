n = int(raw_input())
a = list(map(int, raw_input().split()))

a.sort()

a.insert(0, 0)
n += 1

start = 0
while a[start] == start:
    
    start += 1

    if start == n:
        print("CPU")
        exit(0)

m = n - start

state = 0
if m % 2 == 0:
    for i in range(start, n, 2):
        #print("index = ", i)
        state ^= (a[i+1] - a[i] - 1)
else:
    for i in range(start, n+1, 2):
        #print("index = ", i)
        state ^= (a[i] - a[i-1] - 1)

if state == 0:
    print("CPU")
else:
    print("TUAN")
