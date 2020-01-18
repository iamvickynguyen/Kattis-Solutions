x = input()
count = [[x, 0] for x in range(10)]

# count how many times a number repeats
for i in range(len(x)):
    count[int(x[i])][1] += 1

# sort frequency in ascending order. If equal, sort by value
# output the first one * (its frequency + 1)
# if the first one is 0, compare its frequency with the second one
sorted_count = sorted(count, key=lambda x: x[1])
if sorted_count[0][0] == 0:
    if sorted_count[1][1] - sorted_count[0][1] > 0:
        print(str(sorted_count[1][0]) + '0'*(sorted_count[0][1]+1))
    else:
        print(str(sorted_count[1][0])*(sorted_count[1][1] + 1))
else:
    print(str(sorted_count[0][0])*(sorted_count[0][1] + 1))
