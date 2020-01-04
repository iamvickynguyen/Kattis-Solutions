import sys
import heapq

# Graph: [[[neighbour vertex, weight], [neighbour vertex, weight], ...],[[neighbour vertex, weight], [neighbour vertex, weight], ...],None, ...]


def Dijkstra(graph, s):
    dist = [sys.maxsize]*len(graph)
    dist[s] = 0
    q = []

    for v in range(len(graph)):
        tmp = (dist[v], v)
        heapq.heappush(q, tmp)

    while len(q) > 0:
        item = heapq.heappop(q)
        u = item[1]
        if graph[u] != None:
            for i in range(len(graph[u])):
                v = graph[u][i][0]
                relax = dist[u] + graph[u][i][1]
                if relax < dist[v]:
                    dist[v] = relax

                    # update queue
                    heapq.heappush(q, (relax, v))
    return dist


ip = input()
while(ip != '0 0 0 0'):
    data = [int(x) for x in ip.split()]
    n, m, q, s = data[0], data[1], data[2], data[3]

    # make a graph
    graph = [None]*n
    for _ in range(m):
        info = [int(x) for x in input().split()]
        if graph[info[0]] == None:
            tmp = [info[1:]]
            graph[info[0]] = tmp
        else:
            graph[info[0]].append(info[1:])

    # find shortest path
    dist = Dijkstra(graph, s)
    for _ in range(q):
        d = dist[int(input())]
        print("Impossible") if d == sys.maxsize else print(d)

    ip = input()
