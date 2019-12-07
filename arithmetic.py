# def to_base_10(num, b):
#     num = [int(x) for x in str(num)]
#     result = 0
#     x = len(num) - 1
#     for i in range(len(num)):
#         result += num[i]*(b**x)
#         x -= 1
#     return result


# n = int(input())
# x = hex(to_base_10(n, 8))
# num = [x for x in str(x)]
# x = ''.join(map(str, num[2:]))
# print(x.upper())
def tohex(n):
    result = 0
    dict = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    for i in range(4):
        result += int(n[i]) * (2**(3-i))
    if result in dict:
        return dict[result]
    return str(result)


num = [int(x) for x in str(input())]
s = ''
for i in num:
    s += str(bin(i)[2:].zfill(3))
if len(s) % 4 != 0:
    for j in range(4 - (len(s) % 4)):
        s = '0' + s

result = ''
while len(s) > 0:
    # x = hex(int(s[:4]))[2:]
    debug = s[:4]
    x = tohex(debug)
    result += str(x).upper()
    s = s[4:]

print(result)
