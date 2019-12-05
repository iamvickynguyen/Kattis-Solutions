d = int(input())
r = int(input())
t = int(input())

# rita: [4 + ... + (2+d)] + (3+d) + (4+d) + ... + (i+d)
# theo:                     3     + 4   + ... + i
# sum of candles = [4 + ... + (2+d)] + (2*3+d + 2*4+d + ... + 2*i+d) = x + y
x = sum(range(4, 3+d))
i = 3
y = 2*i+d
while y < (r+t) - x:
    i += 1
    y += 2*i+d

real_candles = sum(range(4, i+d+1))
remove = r - real_candles
print(remove)
