import heapq
import sys

max_heap, min_heap = [], []
for line in sys.stdin:
    line = line.strip()
    if line == '#':
        print(min_heap[0])
        heapq.heappop(min_heap)
        if len(max_heap) > len(min_heap):
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
    else:
        if len(max_heap) == len(min_heap):
            heapq.heappush(min_heap, -heapq.heappushpop(max_heap, -int(line)))
        else:
            heapq.heappush(max_heap, -heapq.heappushpop(min_heap, int(line)))