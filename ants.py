import sys

def count(A, length):
    A.sort()
    _max = max([length - A[0], A[-1]])
    _min = length
    pivot = length/2
    for x in range(len(A)):
        _min = min(_min, abs(A[x] - pivot))      
    return str(int(length/2 - _min)) + " " + str(_max)

cases = int(input())
for i in range(cases):
    line1 = [int(x) for x in input().split(" ")]
    arr = []
    while line1[1] > len(arr):
        arr += [int(x) for x in input().split(" ")]
    print(count(arr, line1[0]))