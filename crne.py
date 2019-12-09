n = int(input())
if n % 2 == 0:
    print((n//2 + 1)**2)
else:
    x = (n+1)//2
    print(x*(x+1))
