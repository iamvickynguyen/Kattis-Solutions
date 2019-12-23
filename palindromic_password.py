# find lower and upper palindrome for 2 digits at index 2,3
def find_2_digits_palindrome(n):
    lower = n
    while lower % 10 != lower//10:
        lower -= 1
    if lower == 0:
        lower = "00"
    upper = n
    while upper % 10 != upper//10:
        upper += 1
    return str(lower), str(upper)


def print_result(num1, num2, num):
    if abs(num1 - int(num)) < abs(num2 - int(num)):
        print(num1)
    elif abs(num1 - int(num)) > abs(num2 - int(num)):
        print(num2)
    elif num1 < num2:
        print(num1)
    else:
        print(num2)


line = int(input())
for i in range(line):
    num = input()

    # if number at index 2,3 are 99 or 00, increment by 1 or decrement by 1
    if int(num[2:4]) == 99:
        front = str(int(num[:3]) + 1)
        num1 = int(front + front[::-1])
        num2 = int(num[:3] + num[2::-1])
        print_result(num1, num2, num)
    elif int(num[2:4]) == 00:
        front = str(int(num[:3]) - 1)
        num1 = int(front + front[::-1])
        num2 = int(num[:3] + num[2::-1])
        print_result(num1, num2, num)

    # else find lower and upper palindromic number for number at index 2,3
    # then compare
    else:
        lower, upper = find_2_digits_palindrome(int(num[2:4]))
        num1 = int(num[:2] + lower + num[1::-1])
        num2 = int(num[:2] + upper + num[1::-1])
        print_result(num1, num2, num)
