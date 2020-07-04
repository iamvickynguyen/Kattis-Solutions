votes = dict()
name = input()
while (name != "***"):
    if name not in votes:
        votes[name] = 1
    else:
        votes[name] += 1
    name = input()

count = dict()
for k, v in votes.items():
    if v not in count:
        count[v] = [k]
    else:
        count[v].append(k)

highest = max(count.keys())
if len(count[highest]) > 1:
    print('Runoff!')
else:
    print(count[highest][0])