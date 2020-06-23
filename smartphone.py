from collections import deque
def count(word, suggestion):
    w = deque()
    s = deque()
    for i in word:
        w.append(i)
    for j in suggestion:
        s.append(j)
    while w and s and w[0] == s[0]:
        w.popleft()
        s.popleft()
    return len(w) + len(s)

t = int(input())
for _ in range(t):
    w = input()
    current = input()
    s1 = input()
    s2 = input()
    s3 = input()
    result = min(min(count(w, current), count(w, s1) + 1), min(count(w, s2) + 1, count(w, s3) + 1))
    print(result)

