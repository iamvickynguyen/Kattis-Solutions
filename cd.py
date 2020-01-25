# data = input()
# while data != "0 0":
#     data = data.split()
#     count = 0
#     l = []
#     for i in range(int(data[0])):
#         l.append(int(input()))

#     i1 = 0
#     i2 = int(data[1])
#     while i1 < int(data[0]) and i2 > 0:
#         x = int(input())
#         while i1 < int(data[0]) and l[i1] < x:
#             i1 += 1
#         if i1 >= int(data[0]):
#             break
#         if l[i1] == x:
#             count += 1
#             i1 += 1
#             i2 -= 1
#         elif l[i1] > x:
#             i2 -= 1

#     while i2 > 1:
#         x = input()
#         i2 -= 1

#     print(count)
#     data = input()


while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    a = set(int(input()) for _ in range(n))
    count = 0
    for _ in range(m):
        if int(input()) in a:
            count += 1
    print(count)
