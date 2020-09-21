P = int(input())
for p in range(1, P+1):
	k, m = map(int, input().split())
	isP = True
	for i in range(2, m):
		if m % i == 0:
			isP = False
			break
	if m!=1 and isP:
		vis = set()
		n = m
		while( n != 1 and n not in vis ):
			vis.add(n)
			c = 0
			while(n>0):
				c += (n%10) * (n%10)
				n //= 10
			n = c
		if n == 1:
			print(f"{k} {m} YES")
			continue

	print(f"{k} {m} NO")
