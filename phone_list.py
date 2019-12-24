# idea: sort list of numbers, then check adjacent numbers
tests = int(input())
for _ in range(tests):
    n = int(input())
    listnum = []
    for x in range(n):
        listnum.append(input())
    listnum.sort()
    not_prefix = True
    for i in range(len(listnum)-1):
        if listnum[i+1].startswith(listnum[i]):
            print("NO")
            not_prefix = False
            break

    if not_prefix:
        print("YES")
