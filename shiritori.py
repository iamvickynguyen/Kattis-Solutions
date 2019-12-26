# Idea: use set() to keep track of words, and a variable to track the last letter in the last word
import sys
line = int(input())
words = set()
player = 1
letter = ''
for _ in range(line):
    word = input()
    if word not in words:
        if letter == '':
            letter = word[-1]
        else:
            if word[0] != letter:
                print("Player " + str(player) + " lost")
                sys.exit(0)
        words.add(word)
        letter = word[-1]
        player = 2 if player == 1 else 1
    else:
        print("Player " + str(player) + " lost")
        sys.exit(0)
print("Fair Game")
