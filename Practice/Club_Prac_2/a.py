c = (1, 0, 0)
m = input()
for mm in m:
	if mm == 'A':
		c = (c[1], c[0], c[2])
	elif mm== 'B':
		c = (c[0], c[2], c[1])
	else:
		c = (c[2], c[1], c[0])
if c == (1, 0, 0):
	print(1)
elif c == (0, 1, 0):
	print(2)
else:
	print(3)