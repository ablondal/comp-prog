n, m = map(int, input().split())
D = {(0,1): 0, (1,0): 0, (1,1):1, (1,2): 2, (1,3): 3, (2,1): 2, (2,2): 4, (2,3): 4, (3,1): 3, (3,2): 4}
while(n!=0 or m!=0):
	if (n>=3 and m>=3):
		if (n%2==0 or m%2==0):
			print(m * n // 2)
		else:
			print((m*n - 1) // 2 + 1)
	else:
		print(D[(n,m)])
	n, m = map(int, input().split())


