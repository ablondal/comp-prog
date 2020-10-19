T = int(input())
for t in range(T):
	pts = {}
	goald = {}
	for i in range(12):
		L = input().split()
		t1 = L[0]
		t2 = L[4]
		p1 = int(L[1])
		p2 = int(L[3])
		if t1 not in pts.keys():
			pts[t1] = 0
			goald[t1] = 0
		if t2 not in pts.keys():
			pts[t2] = 0
			goald[t2] = 0
		if p1==p2:
			pts[t1] += 1
			pts[t2] += 1
		elif p1>p2:
			pts[t1] += 3
			goald[t1] += p1-p2
			goald[t2] += p2-p1
		else:
			pts[t2] += 3
			goald[t1] += p1-p2
			goald[t2] += p2-p1
	L = [ (pts[k], goald[k], k) for k in pts.keys()]
	L = sorted(L)
	print(L[-1][2]+' '+L[-2][2])

