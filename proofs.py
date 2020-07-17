n = int(input())
correct = True
assumptions = set()
for i in range(n):
    line = input()
    if line.startswith('->'):
        line = line.split()
        for item in line[1:]:
            assumptions.add(item)
    elif correct:
        line = line.split(' -> ')
        for a in line[0].split():
            if a not in assumptions:
                print(i+1)
                correct = False
                break
        assumptions.add(line[1])
if correct:
    print('correct')