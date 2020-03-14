n = int(input())
for _ in range(n):
    action = input()
    if action.startswith('simon says'):
        print(action[len('simon says '):])
    else:
        print()