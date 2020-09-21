print(990, 50)
MAXN = 5000011
e = 158473
for i in range(1, 991):
	print(int(i//2), e)
	e *= e
	e %= MAXN