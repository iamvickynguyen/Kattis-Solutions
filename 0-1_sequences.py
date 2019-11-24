sequence = input()
one = 0
branch = 1
inversion = 0
for bit in sequence:
    if bit == '1':
        one = (one + branch) % 1000000007
    elif bit == '0':
        inversion = (inversion + one) % 1000000007
    else:
        inversion = (2 * inversion + one) % 1000000007
        one = (2 * one + branch) % 1000000007
        branch = 2 * branch % 1000000007
print(inversion)
