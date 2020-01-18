line = int(input())
for _ in range(line):
    data = [int(x) for x in input().split()]
    r = data[0]
    c = data[1]
    m = 10**9 + 7
    # square on same row or column with first (top left corner) square
    nearfirst = 6
    others = 2  # other squares, 2C1 (choose colour) + 2C1 (choose edge)

    total = 18  # top left square has 18 ways to color
    total *= pow(nearfirst, r + c - 2, m)
    total *= pow(others, (r-1)*(c-1), m)

    # if c-1 != 0:
    #     total *= pow(6, c-1, m)
    #     # total *= 6**(c-1) % m
    # if r-1 != 0:
    #     total *= pow(6, r-1, m)
    #     # total *= 6*(r-1) % m
    # squares = (r-1)*(c-1)
    # total *= pow(2, squares, m)
    # # for i in range(squares):
    # #     total = (total * 2) % m
    print(total)
