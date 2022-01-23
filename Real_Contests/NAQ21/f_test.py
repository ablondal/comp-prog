from random import randrange

s = ''
for _ in range(100000):
	if randrange(2) == 1:
		s += chr(randrange(ord('a'), ord('z')+1))
	else:
		s += chr(randrange(ord('A'), ord('Z')+1)) 

print(s)