startchar = input()[-1]
n = int(input())
lookup = {}
for _ in range(n):
    name = input()
    if name[0] not in lookup:
        lookup[name[0]] = [name]
    else:
        lookup[name[0]].append(name)

if startchar not in lookup:
    print('?')
else:
    notuniq = []
    notfound = True
    for name in lookup[startchar]:
        if name[-1] != startchar:
            if name[-1] in lookup:
                notuniq.append(name)
            else:
                print(name + '!')
                notfound = False
                break
        else:
            if len(lookup[startchar]) == 1:
                print(name + '!')
                notfound = False
                break
            else:
                notuniq.append(name)
    
    if notfound:
        print(notuniq[0])