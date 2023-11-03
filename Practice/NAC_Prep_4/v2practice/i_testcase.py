from random import randrange
n = 16
print(n)
for i in range(n-1):
	g = 40 + randrange(11)
	r = 40 + randrange(11)
	t = randrange(g+r)
	print(g, r, t)