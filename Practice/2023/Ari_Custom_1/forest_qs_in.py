n, q = int(1e5), int(1e5)
print(n, q)
mx = int(1e9)
from random import randrange
for _ in range(n):
	print (randrange(1, mx), randrange(1, mx), randrange(1, mx))

for _ in range(q):
	x1, x2 = sorted([randrange(1, mx//40), randrange(1, mx//40)])
	y1, y2 = sorted([randrange(1, mx//40), randrange(1, mx//40)])
	print(x1, y1, x2, y2)
