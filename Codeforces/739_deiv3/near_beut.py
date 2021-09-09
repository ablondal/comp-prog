import os, sys
t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	ns = str(n)
	m = 1111111111
	# print(digs)
	if (len(set(str(n))) <= k):
		print(n)
		continue
	for ll in range(1, len(str(n))+1):
		nns = ns[:-ll]
		S = set(int(a) for a in nns)
		nnum = len(S)
		if (nnum <= k):
			for l in range(10):
				lnum = 0 if l in S else 1
				can = int(ns[:-ll] + str(l) + '0'*(ll-1))
				ad = int('1'*(ll-1)) if ll>1 else 0
				for r in range(10):
					rnum = 0 if (r in S or l==r) else 1
					if (can >= n and nnum + lnum + rnum <= k):
						m = min(m, int(can))
					can += ad
					
	print(m)