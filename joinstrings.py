t = int(input())
parent = [-1]*t
words = []
for _ in range(t):
    s = input()
    words.append(s)
for _ in range(t-1):
    a,b = map(int, input().split())
    a,b = a-1, b-1
    p = parent[a]
    while p != -1:
        parent[a] = parent[parent[a]]
        a = p
        p = parent[a]

    words[a] += words[b]
    words[b] = ''
    parent[b] = a
for s in words:
    if s != '':
        print(s)
        break