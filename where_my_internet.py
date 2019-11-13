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

def main():    

    info = input().split()
    i = 0
    for k in range(1,int(info[0])+1):
        make_set(k)

    while i<int(info[1]):
        line = input().split()
        union(int(line[0]), int(line[1]))       
        i+=1

    s = 0
    for e in range(1,int(info[0])+1):
        if(find(1) is not find(e)):
            print(e)
        else:
            s+=1

    if(s==int(info[0])) :
        print("Connected")
    

main()