import sys
from collections import deque

n, m = map(int, input().split())
founder = input()
graph = {}
for _ in range(n):
    child, a, b = map(str, input().split())
    if a in graph:
        graph[a].append(child)
    else:
        graph[a] = [child]

    if b in graph:
        graph[b].append(child)
    else:
        graph[b] = [child]

blood_record = {}
queue = deque()
queue.append((founder, sys.maxsize))
while len(queue) > 0:
    val = queue.popleft()

    # update blood_record dict
    if val[0] in blood_record:
        blood_record[val[0]] += val[1]
    else:
        blood_record[val[0]] = val[1]

    # enqueue
    if val[0] in graph:
        for child in graph[val[0]]:
            queue.append((child, val[1]/2))

heir = input()
blood = 0 if heir not in blood_record else blood_record[heir]
for _ in range(m-1):
    claimant = input()
    claimant_blood = 0 if claimant not in blood_record else blood_record[claimant]
    if claimant_blood > blood:
        heir = claimant
        blood = claimant_blood

print(heir)
