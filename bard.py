n = int(input())
e = int(input())
know = [0]*n
for _ in range(e):
    villager = [int(x) for x in input().split()]
    bard_exists = True if 1 in villager[1:] else False

    # find max songs that a person in that evening know
    _max = 0
    for i in range(1, villager[0] + 1):
        _max = max(know[villager[i]-1], _max)

    # update songs
    for i in range(1, villager[0] + 1):
        if bard_exists:
            know[villager[i]-1] += 1
        else:
            know[villager[i]-1] = _max

output = [(x+1) for x in range(n) if know[x] == know[0]]
output.sort()
for v in output:
    print(v)
