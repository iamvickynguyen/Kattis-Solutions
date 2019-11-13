import sys

num = int(input())
i = 1
check = True
while num > 0:
    n = int(input())
    while n > i:
        print(i)
        i+=1
        check = False
    i = n + 1
    num -= 1

if check:
   print("good job")