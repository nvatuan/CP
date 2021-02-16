t = int(input())
move = [i*i for i in range(1, 1000)]
nim = {0 : 0}
for x in range(0, 100005):
    state = nim.get(x, 0)
    if state == 0:
        for m in move:
            nim[m+x] = 1

# sample = [nim.get(i, 0) for i in range(10)]
# print(sample)

for tt in range(t):
    n = int(input())
    print(['B', 'A'][nim.get(n, 0)])
    
