import sys
smallest_size = int(input())
papers = [int(x) for x in input().split()]
h = 2**(-3/4)
w = 2**(-5/4)

# if total < 1, "impossible"
total = 0
for i in range (len(papers)):
    total += papers[i]/(2*(i+1))

    # calculate tape


if total < 1:
    print("impossible")
    sys.exit(0)


