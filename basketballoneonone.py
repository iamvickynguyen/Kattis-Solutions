s = input()
a, b = 0, 0
switch = False
for i in range(0, len(s) - 1, 2):
    player, score = s[i], int(s[i + 1])

    if player == 'A':
        a += score
        if switch:
            if a - b >= 2:
                print('A')
        else:
            if a >= 11 and a > b:
                print('A')

    else:
        b += score
        if switch:
            if b - a >= 2:
                print('B')
        else:
            if b >= 11 and b > a:
                print('B')

    if a == b and a == 10:
        switch = True