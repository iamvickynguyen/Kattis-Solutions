# use dfs to find path (i.e. all letters that initial letter can tranform)
def dfs(graph, node, visited):
    if node not in visited:
        visited.append(node)
        if node not in graph:
            return visited
        for n in graph[node]:
            dfs(graph, n, visited)
    return visited


line = [int(x) for x in input().split()]
translation = {}
for i in range(line[0]):
    data = input().split()
    if data[0] in translation:
        translation[data[0]].add(data[1])
    else:
        translation[data[0]] = set(data[1])
for k in translation.keys():
    l = list(translation[k])
    translation[k] = l

# table for lookup
table = {}

for i in range(line[1]):
    words = input().split()
    if len(words[0]) != len(words[1]):
        print("no")
    else:
        for j in range(len(words[0])):
            w = words[0][j]
            not_printed = True
            if w != words[1][j]:
                if w not in table:
                    visited = dfs(translation, w, [])
                    table[w] = set(visited)
                if words[1][j] not in table[w]:
                    print("no")
                    not_printed = False
                    break
        if not_printed:
            print("yes")
