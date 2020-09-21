x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

pts = [[x1,y1],[x2,y2],[x3,y3]]

nX = len(set([x1,x2,x3]))
nY = len(set([y1,y2,y3]))

perms = [[0,1,2],[0,2,1],[1,0,2],[1,2,0],[2,0,1],[2,1,0]]

n = 3

for p in perms:
	npts = [pts[p[0]],pts[p[1]],pts[p[2]]]
	p0 = pts[p[0]]
	p1 = pts[p[1]]
	p2 = pts[p[2]]
	nl = 3
	if p0[0] == p1[0]:
		if p1[0] == p2[0]:
			nl = 1
		elif abs(p1[1]-p0[1]) <= abs(p2[1]-p0[1]):
			nl = min(2,nl)
		else:
			nl = min(3,nl)
	elif p0[1] == p1[1]:
		if p1[1] == p2[1]:
			nl = 1
		elif abs(p1[0]-p0[0]) <= abs(p2[0]-p0[0]):
			nl = min(2,nl)
		else:
			nl = min(3,nl)
	n = min(n, nl)
print(n)











