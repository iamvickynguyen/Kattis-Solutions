# data[0]: number of players, data[1]: min point, data[2]:rows
data = [int(x) for x in input().split()]
dict = {}
winner = {}
# init players's scores
for i in range(data[0]):
    player = input()
    dict[player] = 0
    winner[player] = 0

# calculate scores
no_one = True  # no one wins
for i in range(data[2]):
    line = input().split()
    dict[line[0]] += int(line[1])
    if dict[line[0]] >= data[1] and winner[line[0]] != 1:
        print(line[0] + " wins!")
        winner[line[0]] = 1  # only print one time
        no_one = False

if no_one:
    print("No winner!")
