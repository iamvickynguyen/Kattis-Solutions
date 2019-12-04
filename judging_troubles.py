submissions = int(input())
dict = {}
for i in range(submissions*2):
    key = input()
    if key not in dict:
        dict[key] = 1
    else:
        dict[key] += 1

count = 0
for val in dict.values():
    if val > 1:
        count += val//2

print(count)
