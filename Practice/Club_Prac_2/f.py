B = [list(input()) for x in range(8)]
B[7][0] = '.'
M = input()
p = (7, 0)
d = 0
ds = ((0, 1), (-1, 0), (0, -1), (1, 0))
b = 1
for m in M:
	if (m=='F'):
		p = (p[0]+ds[d][0], p[1]+ds[d][1])
		if p[0]<0 or p[0] > 7 or p[1]<0 or p[1] > 7 or B[p[0]][p[1]] not in ('.','D'):
			print('Bug!')
			b = 0
			break
	elif (m=='L'):
		d = (d+1)%4
	elif (m=='R'):
		d = (d+3)%4
	else:
		p1 = (p[0]+ds[d][0], p[1]+ds[d][1])
		if p1[0]<0 or p1[0] > 7 or p1[1]<0 or p1[1] > 7 or B[p1[0]][p1[1]] != 'I':
			print('Bug!')
			b = 0
			break
		B[p1[0]][p1[1]] = '.'
if b:
	if (B[p[0]][p[1]]=='D'): print('Diamond!')
	else: print('Bug!')

# print(p)
# print(d)
# print(b)
# print( '\n'.join([''.join(bb) for bb in B]))