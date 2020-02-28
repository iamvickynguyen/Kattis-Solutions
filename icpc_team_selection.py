set = int(input())
for _ in range(set):
    n = int(input())
    score = [int(x) for x in input().split()]
    score.sort(reverse=True)
    s = sum(score[:n])
    print(s)
