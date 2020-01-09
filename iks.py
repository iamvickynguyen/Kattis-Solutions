def PrimeFactor(n):
    power = {}
    while not n % 2:
        try:
            power[2] += 1
        except KeyError:
            power[2] = 1
        n //= 2
    i = 3
    while i * i <= n:
        while not n % i:
            try:
                power[i] += 1
            except KeyError:
                power[i] = 1
            n //= i
        i += 2
    if n != 1:
        power[n] = 1
    return power


n = int(input())
num = [int(x) for x in input().split()]

# count total number of power of each factor
factor_num = []
factors_count = {}
for i in num:
    prime = PrimeFactor(i)
    for k, v in prime.items():
        if k not in factors_count:
            factors_count[k] = v
        else:
            factors_count[k] += v
    factor_num.append(prime)

# count the number of operations
# spread factors and count how many times we need to decrease the power
ops = 0
for x in factor_num:
    for f in factors_count.keys():
        actual_power = factors_count[f]//n
        if f not in x:
            ops += actual_power
        elif x[f] < actual_power:
            ops += (actual_power - x[f])

# find gcd
gcd = 1
for k, v in factors_count.items():
    gcd *= k**(v//n)

print(str(gcd) + ' ' + str(ops))
