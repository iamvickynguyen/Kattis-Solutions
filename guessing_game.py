low = 1
high = 10
n = int(input())
numbers = [False]*10
while n != 0:
    response = input()
    if response == 'too high':
        if numbers[n-1] or low > high or n > high or n < low:
            print("Stan is dishonest")
        else:
            numbers[n-1] = True
            high = n - 1
    elif response == 'too low':
        if numbers[n-1] or low > high or n < low or n > high:
            print("Stan is dishonest")
        else:
            numbers[n-1] = True
            low = n + 1
    else:
        if numbers[n-1] or low > high or n < low or n > high:
            print("Stan is dishonest")
        else:
            print("Stan may be honest")
        low = 1
        high = 10
        numbers = [False]*10

    n = int(input())
