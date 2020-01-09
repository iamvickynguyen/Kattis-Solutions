n = int(input())
while n != 0:
    bit = 4 * (2**((n-1960)//10))
    num = 2**bit
    val = 1
    for i in range(1, num):
        val *= i
        if val >= num:
            print(i-1)
            break
    n = int(input())
