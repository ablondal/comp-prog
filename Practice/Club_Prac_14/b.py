n, k = map(int, input().split())

a = list(map(int, input().split()))

b = list(range(n+1))[1:]

b = sorted(b, key=lambda x: a[x-1])

i = 0
tot = 0
while tot <= k and i < len(a):
	tot += a[b[i]-1]
	i+=1
if tot <=k:
	print(n)
	print(' '.join(map(str,b)))
else:
	print(i-1)
	if i-1!=0:
		print(' '.join(map(str,b[:i-1])))