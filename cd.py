# Note: since lists are in order, add everything to the first list, while reading the second list inputs, compare with the first list
# This approach is more optimal than puting Jack's cds into a hash set, then checking if Jill's cd is in the set
# However, Python is slow so you still get "time limit exceeded"
# You can take a look at cd.c, which passed all test cases. 
data = input()
while data != "0 0":
    n, m = map(int, data.split())
    count = 0
    l = []
    for i in range(n):
        l.append(int(input()))

    i1 = 0
    i2 = m
    while i1 < n and i2 > 0:
        x = int(input())
        while i1 < n and l[i1] < x:
            i1 += 1
        if i1 >= int(data[0]):
            break
        if l[i1] == x:
            count += 1
            i1 += 1
            i2 -= 1
        elif l[i1] > x:
            i2 -= 1

    while i2 > 1:
        x = input()
        i2 -= 1

    print(count)
    data = input()


# data = input()
# while data != "0 0":
	# n, m = map(int, data.split())
	# count = 0
	# cd = set()
    # for i in range(n):
        # cd.add(int(input()))

    # for j in range(m):
        # if int(input()) in cd:
            # count += 1

    # print(count)
    # data = input()