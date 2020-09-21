n, m = map(int, input().split())
M = [ input().split() for x in range(m)]
M = [ (M[x][0], int(M[x][1])-1) for x in range(m)]
for x in range(m):
	c = x
	for y in range(n):
		c = int(M[c][1])
	print(M[c][0])