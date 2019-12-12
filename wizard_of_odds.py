data = [int(x) for x in input().split()]
print("You will become a flying monkey!") if 2**data[1] < data[0] else print(
    "Your wish is granted!")
