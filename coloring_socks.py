def countmachines(A, load, threshold):
    A.sort()
    min = A[0]
    temp = 1
    count = 1
    for i in range (1, len(A)):
        if (A[i] - min > threshold) or temp >= load:
            count +=1
            min = A[i]
            temp = 0
        temp += 1
    return count

line1 = [int(x) for x in input().split(" ")]
line2 = [int(x) for x in input().split(" ")]
print(countmachines(line2, line1[1], line1[2]))