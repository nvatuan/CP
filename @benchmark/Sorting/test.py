class MaxHeap:
    def _makeHeap(heap, pos):
        endpos = len(heap)
        childpos = pos * 2 + 1

        if childpos < endpos:
            rightpos = childpos + 1
            if rightpos < endpos and heap[childpos] < heap[rightpos]:
                childpos = rightpos
            if heap[pos] < heap[childpos]:
                heap[childpos], heap[pos] = heap[pos], heap[childpos]
                MaxHeap._makeHeap(heap, childpos)

    
    def heapify(self):
        n = len(self.heap)
        for i in reversed(range(n//2)):
            # MaxHeap._makeHeap(self.heap, i)
            MaxHeap._shiftdown(self.heap, i)

    def heapPush(self, item):
        pushindex = len(self.heap)
        self.heap.append(item)
        MaxHeap._shiftup(self.heap, pushindex)

    def _shiftup(heap, pos):
        parent = (pos-1)//2;
        while parent >= 0:
            if heap[pos] > heap[parent]:
                heap[pos], heap[parent] = heap[parent], heap[pos]
                pos = parent
                parent = (pos - 1)//2;
            else:
                break

    def heapPop(self):
        lastnode = self.heap.pop()

        if self.heap:
            result = self.heap[0]
            self.heap[0] = lastnode
            MaxHeap._shiftdown(self.heap, 0)

            return result
        return lastnode

    def heapSort(self):
        array = []
        while len(self.heap) > 0:
            res = self.heapPop()
            array.append(res)
        return array[::-1]
    
    def _shiftdown(heap, pos):
        endpos = len(heap)
        childpos = pos*2 + 1

        while childpos < endpos:
            rightpos = childpos + 1
            if rightpos < endpos and heap[childpos] < heap[rightpos]: 
                childpos = rightpos

            if heap[pos] < heap[childpos]:
                heap[pos], heap[childpos] = heap[childpos], heap[pos]
                pos = childpos
                childpos = pos*2 + 1
            else:
                break
        
    def __init__(self, arr):
        self.heap = [0] * len(arr)
        
        for pos in range(len(arr)):
            self.heap[pos] = arr[pos]
        
        self.heapify()

    def __repr__(self):
        return str(self.heap[0:self.actualLength])


n = int(input())
a = list(map(int, input().split()))

h = MaxHeap(a)

print(*h.heapSort())

