t = int(input())
for T in range(t):
	print(' '.join([st[::-1] for st in input().split() ]))