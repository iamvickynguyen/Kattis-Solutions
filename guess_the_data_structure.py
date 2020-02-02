import sys
from collections import deque
import heapq

for line in sys.stdin:
    n = int(line.strip())
    array = []
    for _ in range(n):
        array.append(input())

    queue = deque()
    stack=[]
    pq = []
    is_queue = True
    is_stack = True
    is_pq = True
    for item in array:
        x, v = map(int, item.split())
        if x == 1:
            queue.append(v)
            stack.append(v)
            heapq.heappush(pq, -v)
        else:
            if is_queue:
                if len(queue) <= 0 or queue[0] != v:
                    is_queue = False
                else:
                    queue.popleft()
            if is_stack:
                if len(stack) <= 0 or stack[-1] != v:
                    is_stack = False
                else:
                    stack.pop()
            if is_pq:
                if len(pq) <= 0:
                    is_pq = False
                elif -heapq.heappop(pq) != v:
                        is_pq = False
    value = (1 if is_queue else 0) + (1 if is_stack else 0) + (1 if is_pq else 0)
    if value == 0:
        print("impossible")
    elif value > 1:
        print("not sure")
    else:
        if is_queue:
            print("queue")
        elif is_stack:
            print("stack")
        else:
            print("priority queue")