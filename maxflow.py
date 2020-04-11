from collections import deque
import sys
flow = 0

def Edmond_Karp(graph, residual_graph, s, t):
    global flow
    maxflow = 0
    parent = [-1] * len(residual_graph)
    while True:
        flow = 0
        dist = [sys.maxsize] * len(residual_graph)
        dist[s] = 0
        q = deque()
        q.append(s)
        while q:
            u = q.popleft()
            if u == t:
                break # stop BFS if we already reach sink t
            if u in graph:
                for v, w in graph[u].items():
                    if residual_graph[u][v] > 0 and dist[v] == sys.maxsize:
                        dist[v] = dist[u] + 1
                        q.append(v)
                        parent[v] = u
        augment(t, sys.maxsize, s, parent, residual_graph)
        if flow == 0:
            break
        maxflow += flow
    edges = get_edges(graph, residual_graph, t, s)
    return maxflow, edges

def augment(v, min_edge, s, parent, residual_graph):
    global flow
    if v == s:
        flow = min_edge
        return
    elif parent[v] != -1:
        augment(parent[v], min(min_edge, residual_graph[parent[v]][v]), s, parent, residual_graph)
        residual_graph[parent[v]][v] -= flow
        residual_graph[v][parent[v]] += flow

def get_edges(graph, residual_graph, t, s):
    edges = set()
    visited = set()
    q = deque()
    q.append(s)
    while q:
        u = q.popleft()
        visited.add(u)
        if u == t:
            break
        if u in graph:
            for k, v in graph[u].items():
                if v > residual_graph[u][k] and k not in visited:
                    edges.add((u, k, v - residual_graph[u][k]))
                    q.append(k)
    return edges

n,m,s,t = map(int, input().split())
graph = {}
residual_graph = {}
for _ in range(m):
    u,v,x = map(int, input().split())
    if u in graph:
        graph[u][v] = x
    else:
        graph[u] = {v:x}

    if u in residual_graph:
        residual_graph[u][v] = x
    else:
        residual_graph[u] = {v:x}

    if v in residual_graph:
        residual_graph[v][u] = 0
    else:
        residual_graph[v] = {u:0}

maxflow, edges = Edmond_Karp(graph, residual_graph, s, t)
print(n, maxflow, len(edges))
for (u,v,w) in edges:
    print(u,v,w)
