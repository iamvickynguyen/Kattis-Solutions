low = -1
high = 11
n = int(input())
while n != 0:
    response = input()
    if response == 'too high':
        high = min(high, n)
    elif response == 'too low':
        low = max(low, n)
    else:
        if low < high and n > low and n < high:
            print("Stan may be honest")
        else:
            print("Stan is dishonest")
        low = -1
        high = 11

    n = int(input())
