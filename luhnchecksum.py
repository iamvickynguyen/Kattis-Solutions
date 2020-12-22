def sum2digits(s):
    v = str(s * 2)
    return int(v[0]) + int(v[1])

t = int(input())
for _ in range(t):
    s = [int(x) for x in input()]
    total = sum(s[-1::-2])
    total += sum(map(lambda x: x * 2 if x * 2 < 10 else sum2digits(x), s[-2::-2]))   
    print('PASS') if total % 10 == 0 else print('FAIL')