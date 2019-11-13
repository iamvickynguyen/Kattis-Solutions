line = input().split(" ")

row = []
for i in range (int(line[2])):
    row.append(int(input()))

column = []
for i in range (int(line[3])):
    column.append(int(input()))
    
# 1: black, 0: white
bw_row = 1
bw_colume = 1
for i in range (int(line[0])):
    for j in range (int(line[1])):
        for col in column:
            