# Idea: Greedy, similar job sequencing with deadlines
info = [int(x) for x in input().split()]
data = []
for _ in range(info[0]):
    data.append([int(x) for x in input().split()])

# sort money descending
data.sort(key=lambda x: x[0], reverse=True)

# time slots
time = info[1]
slots = [False] * time
total = 0
for i in range(len(data)):
    for j in range(min(time, data[i][1]), -1, -1):
        # if exists free slot
        if slots[j] is False:
            slots[j] = True
            total += data[i][0]
            break

print(total)
