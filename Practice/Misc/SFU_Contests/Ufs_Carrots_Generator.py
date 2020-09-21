import random

n = 1000

m = [0 for x in range(n)]
v = set([0])

for x in range(n):
	while(m[x] in v):
		m[x] = random.randrange(1, 100001)
	v.add(m[x])

print(n)
print(' '.join(map(str,m)))