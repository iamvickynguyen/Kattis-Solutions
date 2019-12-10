def pad0(x, y):
    if len(y) < len(x):
        while len(y) < len(x):
            y = '0' + y
    else:
        while len(x) < len(y):
            x = '0' + x
    return x, y


x = input()
while x != '0 0':
    data = x.split(" ")
    x, y = pad0(data[0], data[1])
    count = 0
    carry = 0
    for i in reversed(range(len(x))):
        carry = (int(x[i]) + int(y[i]) + carry) // 10
        if carry > 0:
            count += carry

    if count == 0:
        print("No carry operation.")
    elif count == 1:
        print("1 carry operation.")
    else:
        print(str(count) + " carry operations.")

    x = input()
