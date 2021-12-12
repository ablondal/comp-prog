n, m = map(int, input().split())
from collections import Counter

c = Counter()
g = False
for i in range(n):
	s = input()
	ssum = sum([1 if c=='1' else 0 for c in s])
	if ( ssum <= 15 and ssum >= 8 ):
		c[s] += 1
		g = True

if g:
	print(c.most_common(1)[0][0])
else:
	print('1'*8 + '0'*(m-8))