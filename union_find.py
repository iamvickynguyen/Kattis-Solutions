Parent, Size = {}, {}
def make_set(elem):
    Parent[elem] = elem
    Size[elem] = 1

def find(elem):
    while Parent[elem] is not elem:
        Parent[elem] = Parent[Parent[elem]]
        elem = Parent[elem]
    return elem

def union(elem1, elem2):
    root1, root2 = find(elem1), find(elem2)
    if root1 is not root2:
        if Size[root1] < Size[root2]:
            root1, root2 = root2, root1
        Parent[root2] = root1
        Size[root1] += Size[root2]

line = [int(x) for x in input().split()]
for i in range(line[0]):
    make_set(i)

for j in range(line[1]):
    data = input().split()
    if data[0] == '?':
        if find(int(data[1])) is not find(int(data[2])):
            print("no")
        else:
            print("yes")
    else:
        union(int(data[1]), int(data[2]))