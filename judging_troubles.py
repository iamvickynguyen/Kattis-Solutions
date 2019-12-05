n = int(input())
dom = {}
for i in range(n):
    judge = input()
    if judge not in dom:
        dom[judge] = 1
    else:
        dom[judge] += 1

kattis = {}
for i in range(n):
    judge = input()
    if judge not in kattis:
        kattis[judge] = 1
    else:
        kattis[judge] += 1

# compare 2 dictionaries, find match
count = 0
for key in dom.keys():
    if key in kattis:
        count += min(dom[key], kattis[key])

print(count)
