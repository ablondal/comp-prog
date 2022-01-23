N = 100000
M = 100000
print(N)
print(M)
edg = set();
from random import randrange;
for _ in range(M):
	u = randrange(1,N+1)
	v = randrange(1,N+1)
	while u == v or (u, v) in edg or (v, u) in edg:
		u = randrange(1,N+1)
		v = randrange(1,N+1)
	print(str(u)+" "+str(v))