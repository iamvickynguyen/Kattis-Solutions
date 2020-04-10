from collections import deque
import sys
from copy import deepcopy
flow = 0

def Edmond_Karp(graph, s, t):
    global flow
    maxflow = 0
    residual_graph = [row[:] for row in graph]
    parent = [-1] * len(graph)
    while True:
        flow = 0
        dist = [sys.maxsize] * len(graph)
        dist[s] = 0
        q = deque()
        q.append(s)
        while q:
            u = q.popleft()
            if u == t:
                break # stop BFS if we already reach sink t
            for v in range(len(graph[u])):
                if residual_graph[u][v][1] > 0 and dist[v] == sys.maxsize:
                    dist[v] = dist[u] + 1
                    q.append(graph[u][v][0])
                    parent[graph[u][v][0]] = u
        augment(t, sys.maxsize, s, parent, residual_graph)
        if flow == 0:
            break
        maxflow += flow
    s, edges = get_edges(graph, residual_graph)
    return maxflow, s, edges

def augment(v, min_edge, s, parent, residual_graph):
    global flow
    if v == s:
        flow = min_edge
        return
    elif parent[v] != -1:
        augment(parent[v], min(min_edge, residual_graph[parent[v]][v]), s, parent, residual_graph)
        residual_graph[parent[v]][v] -= flow
        residual_graph[v][parent[v]] += flow

def get_edges(graph, residual_graph):
    edges = 0
    s = ''
    for i in range(len(graph)):
        for j in range(len(graph)):
            if graph[i][j] > residual_graph[i][j]:
                flow = graph[i][j] - residual_graph[i][j]
                s += str(i) + ' ' + str(j) + ' ' + str(flow) + '\n'
                edges += 1
    return s, edges

n,m,s,t = map(int, input().split())
graph = [[] for i in range(n)]
for _ in range(m):
    u,v,x = map(int, input().split())
    graph[u].append({v:x})
    graph[v].append({u:x})
maxflow, s, edges = Edmond_Karp(graph, s, t)
print(n, maxflow, edges)
print(s)