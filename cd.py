data = input()
while data != "0 0":
    data = data.split()
    count = 0
    cd = set()
    for i in range(int(data[0])):
        cd.add(int(input()))

    for j in range(int(data[1])):
        if int(input()) in cd:
            count += 1

    print(count)
    data = input()
