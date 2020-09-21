import random
import string

letters = string.ascii_lowercase

print(50)
for x in range(50):
	name = []
	for y in range(5):
		name.append(''.join(random.choice(letters) for i in range(9)))
	print(' '.join(name))