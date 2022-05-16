n = 100000
k = n//2
from random import randrange
print(n, k)
for i in range(n):
	print(randrange(1, 101), i*5)