t = int(input())

for T in range(t):
	n = int(input())
	s = input()
	ones = [-1 for i in range(n)]
	io = 0
	zero = [-1 for i in range(n)]
	iz = 0
	j = 1
	ans = [0 for i in range(n)]
	for i in range(n):
		if s[i]=='0':
			if io > 0:
				ans[i] = ones[io-1]
				io-=1
			else:
				ans[i] = str(j)
				j+=1
			zero[iz] = ans[i]
			iz+=1
		else:
			if iz > 0:
				ans[i] = zero[iz-1]
				iz-=1
			else:
				ans[i] = str(j)
				j+=1
			ones[io] = ans[i]
			io+=1
	print(j-1)
	print(" ".join(ans))

