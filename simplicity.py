text = input()
dict = {}

# create a dictionary dict = {character: frequency}
for i in text:
    if i not in dict:
        dict[i] = 1
    else:
        dict[i] += 1

# sort dict by frequency
# calculate the total frequency of items that have lowest frequency, until there are < or = 2 items in dict
if len(dict) < 3:
    print(0)
else:
    total = 0
    value = sorted(dict.values())
    for i in range(len(value)-2):
        total += value[i]
    print(total)
