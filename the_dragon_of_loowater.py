info = input()
while info != '0 0':
    info = info.split()
    heads = []
    knights = []
    h, k = int(info[0]), int(info[1])
    for _ in range(h):
        heads.append(int(input()))
    for _ in range(k):
        knights.append(int(input()))

    if k < h:
        print('Loowater is doomed!')
    else:
        heads.sort()
        knights.sort()
        coins = 0
        head_index = 0
        for i in range(k):
            if head_index >= h:
                break
            if knights[i] >= heads[head_index]:
                coins += knights[i]
                head_index += 1

        if head_index == h:
            print(coins)
        else:
            print('Loowater is doomed!')

    info = input()
