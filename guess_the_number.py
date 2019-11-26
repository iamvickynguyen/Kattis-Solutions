import sys

# idea: binary search
# the program will exit after guessing 10 times or the response == 'correct'
left = 1
right = 1000
for i in range(10):
    mid = left + (right-left)//2
    print(mid, flush=True)
    response = input()
    if response == 'correct':
        sys.exit(0)
    if response == 'lower':
        right = mid - 1
    elif response == 'higher':
        left = mid + 1
sys.exit(0)
