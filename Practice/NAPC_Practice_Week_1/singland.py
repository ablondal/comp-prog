a, t = map(int, input().split())

from random import randrange

for _ in range(t):
	e = input().split()
	s = ''.join(e[1:])
	tot = 0
	z = [0 for _ in range(len(s))]
	l = -1
	r = -1
	for i in range(1, len(s)):
		z[i] = 0 if i>=r else min(r-i, z[i-l])
		while (i + z[i] < len(s) and s[i+z[i]] == s[z[i]]):
			z[i]+=1
		if (i+z[i] > r):
			l = i
			r = i + z[i]
	print(z)
	for _ in range(10000):
		t = ''
		i = 0
		while(len(t) < len(s) or t[-len(s):] != s):
			i += 1
			t += ( chr(ord('0') + randrange(1, a+1)) )
		tot += i
	print(tot/10000)