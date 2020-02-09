name_party = {}
votes = {}
n = int(input())
for _ in range(n):
    candidate = input()
    name_party[candidate] = input()
m = int(input())
for _ in range(m):
    name = input()
    if name not in votes:
        votes[name] = 1
    else:
        votes[name] += 1

sorted_votes = [(k, v) for k, v in sorted(
    votes.items(), key=lambda item: item[1], reverse=True)]
if len(sorted_votes) == 0 or (len(sorted_votes) > 1 and sorted_votes[0][1] == sorted_votes[1][1]):
    print('tie')
else:
    print(name_party[sorted_votes[0][0]])
