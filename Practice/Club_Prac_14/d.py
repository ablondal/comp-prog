gr = [input() for x in range(3)]
grid = [gr[x//3][x%3] for x in range(9)]

nX = 0
nO = 0
for x in range(9):
	if grid[x] == 'X':
		nX+=1
	if grid[x] == '0':
		nO+=1
turn = -1
if nO==nX:
	turn = 0
elif nX == nO+1:
	turn = 1
else:
	print('illegal')

if (turn !=-1):
	aw = False
	bw = False
	for l in ((0,1,2),(3,4,5),(6,7,8),(0,3,6),(1,4,7),(2,5,8),(0,4,8),(2,4,6)):
		if (grid[l[0]] == grid[l[1]] and grid[l[0]] == grid[l[2]]):
			if grid[l[0]]=='X':
				aw = True
			if grid[l[0]]=='0':
				bw = True
	if aw and bw:
		print('illegal')
	elif aw:
		if turn == 1:
			print('the first player won')
		else:
			print('illegal')
	elif bw:
		if turn == 0:
			print('the second player won')
		else:
			print('illegal')
	elif (nO+nX==9):
		print('draw')
	else:
		print('first' if turn==0 else 'second')



















