end = input()[-1]
dict = {}
invalid = set()
potential = set()
potential_ordered = []
n = int(input())
for _ in range(n):
    word = input()
    if word[0] == end:
        if word[-1] in dict:
            dict[word[-1]].append(word)
        else:
            dict[word[-1]] = [word]
        potential_ordered.append(word)
    else:
        invalid.add(word[0])


for k, v in dict.items():
    if k not in invalid:
        for w in v:
            potential.add(w)

if not potential_ordered:
    print("?")
elif len(potential) == 1:
    for result in potential:
        print(result + "!")
else:
    if not potential:
        print(potential_ordered[0])
    else:
        for item in potential_ordered:
            if item in potential:
                print(item)
                break
