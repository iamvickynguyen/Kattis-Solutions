line = int(input())
people = {}
words = {}  # count frequency

# add to words dictionary
# return list of words that person said


def add_to_dict(l):
    unique_word = set()
    for i in l:
        unique_word.add(i)
        if i not in words:
            words[i] = 1
        else:
            words[i] += 1
    return unique_word


for _ in range(line):
    log = input().split()
    w = add_to_dict(log[1:])
    if log[0] not in people:
        people[log[0]] = w
    else:
        for item in w:
            people[log[0]].add(item)

# take all words that everyone said
word_set = set.intersection(*people.values())

if len(word_set) == 0:
    print("ALL CLEAR")
else:
    # take frequency of words that everyone said
    sorted_dict = sorted(words.items(), key=lambda item: item[1], reverse=True)
    _max = sorted_dict[0][1]
    temp = [sorted_dict[0][0]]  # sort alphabetically
    for i in range(1, len(sorted_dict)):
        if sorted_dict[i][0] in word_set:
            if sorted_dict[i][1] < _max:
                temp.sort()
                for w in temp:
                    print(w)
                _max = sorted_dict[i][1]
                temp.clear()
            temp.append(sorted_dict[i][0])

    # dump everything
    if len(temp) > 0:
        for e in temp:
            print(e)
