# Idea: using KMP algo
import sys
Max_N = 100010
b = [0 for i in range(Max_N)]


def KMP(T, P):
    n = len(T)
    m = len(P)
    i = 0
    j = -1
    b[0] = -1
    while i < m:
        while j >= 0 and P[i] != P[j]:
            j = b[j]
        i += 1
        j += 1
        b[i] = j


def search(T, P):
    n = len(T)
    m = len(P)
    i = 0
    j = 0
    while i < n:
        while j >= 0 and T[i] != P[j]:
            j = b[j]
        i += 1
        j += 1
        if j == m:
            print(str(i-j), end=' ')
            j = b[j]
    print()


for line in sys.stdin:
    P = line.strip()
    T = input()
    KMP(T, P)
    search(T, P)
