import heapq
from bisect import bisect_left 

def binary_search_reverse(a, x, lo=0, hi=None):
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if x > a[mid]: hi = mid
        else: lo = mid+1
    return lo

dict = {}
line = int(input())
for _ in range(line):
    ip = input().split()
    if ip[0] == 'add':
        e, g = int(ip[1]), int(ip[2])
        if e in dict:
            heapq.heappush(dict[e], -g) # max heap
        else:
            dict[e] = [-g]
    else:
        total = 0
        start_index = 0
        x = int(ip[1])
        tmp = sorted(dict.keys(), reverse = True)
        while x > 0 and len(dict) > 0:
            if x in dict:
                g = heapq.heappop(dict[x])
                total -= g
                if len(dict[x]) == 0:
                    del dict[x]
                x = 0
            else:
                i = binary_search_reverse(tmp, x, start_index, len(tmp))
                if i == len(tmp):
                    break
                e = tmp[i]
                g = heapq.heappop(dict[e])
                total -= g
                x -= e
                if len(dict[e]) == 0:
                    del dict[e]
                    start_index = i+1
                if x < e:
                    start_index = i + 1
        print(total)