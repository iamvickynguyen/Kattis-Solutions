t = int(input())

for _ in range(t):
    blank = input()
    n = int(input())
    candies = 0
    for i in range(n):
        candies = (int(input()) % n + candies % n) % n
    if candies == 0:
        print("YES")
    else:
        print("NO")
