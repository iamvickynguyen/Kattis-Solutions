#KADANE 'S 
def Kadane(A):
    signma = -1001
    for i in range(1, len(A)):
        new = A[i-1] + A[i]
        if new > A[i]:
            A[i] = new
        if signma < A[i]:
            signma = A[i]
    return signma

C = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

for i in range(len(B)):
    B[i] = B[i]-C[1]

print(str(Kadane(B)))