D = {}
C = {}
c, k = map(int, input().split())

for i in range(c):
	a, b = input().split()
	b = int(b)
	C[a] = b
	D[a] = []

for i in range(k):
	a, b = input().split()
	b = int(b)
	if D.get(a) != None:
		D[a].append(b)

tot = 0
for col in C.keys():
	D[col].sort(reverse=True)
	a = min( len(D[col]), C[col] )
	tot += sum( D[col][:a] )

print(tot)