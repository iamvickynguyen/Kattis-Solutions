attrlist = input()
attr = {value: index for index, value in enumerate(attrlist.split())}
m = int(input())
songs = [input().split() for i in range(m)]
n = int(input())
for i in range(n):
    sortby = attr[input()]
    songs.sort(key=lambda x: x[sortby])
    print(attrlist)
    for s in songs:
        print(" ".join(s))
    
    if i < n - 1:
        print()