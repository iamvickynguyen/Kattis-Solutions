import math
alphabet = {i: chr(i+96) for i in range(1, 27)}
ip = input().split()
l, w = int(ip[0]), int(ip[1])
if w/l > 26 or w/l < 1:
    print('impossible')
else:
    s = ''
    ceil = w-math.ceil(w/l)*(l-1)
    floor = w-math.floor(w/l)*(l-1)
    if ceil > 0 and ceil <= 26:
        s = (l-1)*alphabet[math.ceil(w/l)]
        another_letter = alphabet[ceil]
    else:
        s = (l-1)*alphabet[math.floor(w/l)]
        another_letter = alphabet[floor]
    s += another_letter
    print(s)
