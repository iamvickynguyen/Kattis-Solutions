import heapq
n, m = map(int, input().split())
q = []
for _ in range(n):
    heapq.heappush(q, tuple(int(x) for x in input().split()))

available = []
count = 1
a, b = heapq.heappop(q)
heapq.heappush(available, a+b)
i = n
while i > 1:
    a, b = heapq.heappop(q)
    if len(available) <= 0:
        count += 1
        heapq.heappush(available, a+b)
    else:
        if a < available[0]:
            count += 1
            heapq.heappush(available, (a+b))
        elif a - available[0] <= m:
            heapq.heapreplace(available, (a+b))
        else:
            t = heapq.heappop(available)
            while len(available) > 0 and a-t > m:
                t = heapq.heappop(available)
            if len(available) <= 0 and a-t > m:
                count += 1
            heapq.heappush(available, a+b)
    i -= 1
print(n-count)
