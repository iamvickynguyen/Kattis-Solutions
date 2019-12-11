import sys

# ============ TEST ===================
# A Dynamic Programming based Python Program for 0-1 Knapsack problem 
# Returns the maximum value that can be put in a knapsack of capacity W 
def knapSack(W, wt, val, n): 
    K = [[0 for x in range(W+1)] for x in range(n+1)] 
  
    # Build table K[][] in bottom up manner 
    for i in range(n+1): 
        for w in range(W+1): 
            if i==0 or w==0: 
                K[i][w] = 0
            elif wt[i-1] <= w: 
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]) 
            else: 
                K[i][w] = K[i-1][w] 
  
    return K[n][W] 

# idea: sort time ascending, take the max money if some customers leave at the same time
line = [int(x) for x in input().split()]
close = line[1]
data = [None]*close
for _ in range(line[0]):
    temp = [int(x) for x in input().split()]
    if temp[1] < close:
        if data[temp[1]] == None:
            data[temp[1]] = temp[0]
        else:
            data[temp[1]] = max(temp[0], data[temp[1]])


val = []
time = []
for j in range(close):
    if data[j] != None:
        val.append(data[j])
        time.append(j)

n = len(val) 
print(knapSack(close, time, val, n)) 
           

