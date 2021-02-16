import heapq
n = int(input())
a = list(map(int, input().split()))

heapq.heapify(a)
arr = []
while len(a) > 0:
    arr.append(heapq.heappop(a))
print(*arr)