import heapq

def mst(adj_list, pq, taken):
    process(0, adj_list, pq, taken)
    mst_cost = 0
    edge_list = []
    while pq:
        (min_weight, vertex, start) = heapq.heappop(pq)
        if vertex not in taken:
            edge_list.append((start, vertex) if start < vertex else (vertex, start))
            mst_cost += min_weight
            process(vertex, adj_list, pq, taken)
    return mst_cost, edge_list

def process(v, adj_list, pq, taken):
    taken.add(v)
    for i in range(len(adj_list[v])):
        (neighbour, weight) = adj_list[v][i]
        if neighbour not in taken:
            heapq.heappush(pq, (weight, neighbour, v))

n,m = map(int, input().split())
while (n,m) != (0,0):
    adj_list = {}
    pq = []
    taken = set()
    for _ in range(m):
        u,v,w = map(int, input().split())

        if u in adj_list:
            adj_list[u].append((v,w))
        else:
            adj_list[u] = [(v,w)]

        if v in adj_list:
            adj_list[v].append((u,w))
        else:
            adj_list[v] = [(u,w)]

    if len(adj_list) < n:
        print('Impossible')
    else:
        mst_cost, edge_list = mst(adj_list, pq, taken)
        edge_list.sort(key=lambda x: (x[0], x[1]))
        print(mst_cost)
        for item in edge_list:
            print(item[0], item[1])

    n,m = map(int, input().split())