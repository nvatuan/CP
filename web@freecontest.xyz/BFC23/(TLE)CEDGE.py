tree = {}
edge_id = {}

n = int(input())
for i in range(n): tree[i] = []

for i in range(1, n):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    tree[a].append(b)
    tree[b].append(a)

    edge_id[(a, b)] = i-1
    edge_id[(b, a)] = i-1

from queue import Queue
q = Queue()
q.put(0)
vis = {}

max_degree = 0
ans = [0] * (n-1)

while q.qsize() > 0:
    front = q.get()
    if vis.get(front, False): continue
    vis[front] = True

    max_degree = max(max_degree, len(tree[front]))
    mex = 0
    mex_table = {}

    for x in tree[front]:
        mex_table[ans[edge_id[(front, x)]]] = True
        if vis.get(x, False): continue
        q.put(x)
    
    for x in tree[front]:
        if ans[edge_id[(front, x)]] == 0:
            while mex_table.get(mex) != None:
                mex += 1
            ans[edge_id[(front, x)]] = mex
            mex += 1
                
print(max_degree)
print(*ans, sep ='\n')