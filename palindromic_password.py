line = int(input())
for i in range(line):
    num = [x for x in input()]
    front = ''
    back = ''
    while len(num) > 0:
        if int(num[0]) > int(num[-1]) and int(num[-1]) != 0:
            front += num[-1]
            back = num[-1] + back
        else:
            front += num[0]
            back = num[0] + back
        num = num[1:-1]
    print(front+back)
