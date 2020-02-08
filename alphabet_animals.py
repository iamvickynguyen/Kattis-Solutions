end = input()[-1]
dict = {}
invalid = set()
potential = set()
list_results_ordered = []
not_end_with_end = []
n = int(input())
for _ in range(n):
    word = input()
    if word[0] == end:
        if word[-1] in dict:
            dict[word[-1]].append(word)
        else:
            dict[word[-1]] = [word]
        list_results_ordered.append(word)
    else:
        invalid.add(word[0])

# remove to reduce list
for k, v in dict.items():
    if k not in invalid:
        for w in v:
            potential.add(w)
            if w[-1] != end:
                not_end_with_end.append(w)

if not list_results_ordered:
    print("?")
elif not_end_with_end:
    for item in list_results_ordered:
        if item in not_end_with_end:
            print(item + "!")
            break
elif len(potential) == 1 and ((len(list_results_ordered) > 1 and list(potential)[0][-1] != end) or (len(list_results_ordered) == 1)):
    print(list_results_ordered[0] + "!")  # unique
else:
    if not potential:
        print(list_results_ordered[0])

    # check if word[-1] == end:
    #   iterate through the whole list to find, if none take the first 1 that also shows up in list_results_ordered
    # else: append to a list, then output what's come first
    else:
        result = ''
        potential_results = []
        first = True
        for item in list_results_ordered:
            if item in potential:

                # keep first word
                if first:
                    result = item
                    first = False

                # check if word[-1] != end
                if item[-1] != end:
                    result = item + "!"
                    break

        print(result)
