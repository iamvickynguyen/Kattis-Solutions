import sys

def checkpalindrom(A):
    stack=[]
    stack.append(A[0])
    for x in range(1,len(A)):
        if(stack):
            item = stack[-1]
            if(item == A[x]):
                stack.pop()
            else:
                stack.append(A[x])
        else:
            stack.append(A[x])
    if(stack):
        return 'impossible'
    return len(A)

def main():
    line1 = input()
    arr = [int(x) for x in input().split(" ")]
    print(checkpalindrom(arr))

main()
