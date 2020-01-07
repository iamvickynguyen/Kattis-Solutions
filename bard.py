n = int(input())
e = int(input())
know = [0]*n
new_songs = []
for _ in range(e):
    villager = [int(x) for x in input().split()]
    bard_exists = True if 1 in villager[1:] else False

    # if bard exists, create new set
    if bard_exists:
        new_songs.append(set(villager[1:]))
    # else, check if in that evening if there is someone know any song from other days
    # if yes, put all of them in that set
    else:
        for item in new_songs:
            for x in villager[1:]:
                if x in item:
                    item |= set(villager[1:])
                    break

# count number of songs each villager knows
for i in range(1, n+1):
    for s in new_songs:
        if i in s:
            know[i-1] += 1

output = [(x+1) for x in range(n) if know[x] == know[0]]
output.sort()
for v in output:
    print(v)
