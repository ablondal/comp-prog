print(1)
print(1000)
from random import randrange
L = []
for x in range(2000):
	L.append(str(randrange(1, 1e6)))
print(" ".join(L))