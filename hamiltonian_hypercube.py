def get_bin_sear_ID(a):
    ID = 0
    iter = '1'
    add = int(2**n)
    for bit in a:
        add //= 2
        if bit == iter:
            ID += add
            iter = '0'
        else:
            iter = '1'
    return ID


data = input().split()
n, a, b = int(data[0]), data[1], data[2]
print(get_bin_sear_ID(b) - get_bin_sear_ID(a) - 1)
