# Confirms Superdoku returns a Latin Square

ans = input();
l0 = input().split();
n = len(l0)
L = [[0 for x in range(len(l0))] for y in range(len(l0))]
L[0] = [int(x) for x in l0]
for y in range(1,len(l0)):
	L[y] = [int(x) for x in input().split()]



for x in range(n):
	R = set()
	for y in range(n):
		if (L[y][x] in R):
			print("not LATIN SQUARE")
			exit(0);
		R.add(L[y][x])

for y in range(n):
	R = set()
	for x in range(n):
		if (L[y][x] in R):
			print("not LATIN SQUARE")
			exit(0);
		R.add(L[y][x])

print("IS LATIN SQUARE")