# done

t = int(input())

mx = 2**32

bases = ''

for i in range(t):
	b = -1
	bases = ''
	L = input().split()
	# print(L)
	for B in range(36, 1, -1):
		w = False
		a=mx
		b=mx
		c=mx
		try:
			a=int(L[0], B)
			b=int(L[2], B)
			c=int(L[4], B)
		except:
			# print("invalid in base "+str(B))
			continue
		if a>=mx or b>=mx or c>=mx:
			continue
		if L[1] == "+":
			if a+b==c:
				w = True
		elif L[1]=='-':
			if a-b==c:
				w=True
		elif L[1]=='*':
			if a*b==c:
				w=True
		elif L[1]=='/':
			if a/b==c:
				w=True
		if w == True:
			ad = ''
			if B == 36: ad='0'
			elif B >9: ad=chr(ord('a')+B-10)
			else: ad = str(B)
			bases = ad+bases
	if (L[0] == '1'*len(L[0]) and L[2]=='1'*len(L[2]) and L[4]=='1'*len(L[4])):
		a=len(L[0])
		b=len(L[2])
		c=len(L[4])
		w=False
		if L[1] == "+":
			if a+b==c:
				w = True
		elif L[1]=='-':
			if a-b==c:
				w=True
		elif L[1]=='*':
			if a*b==c:
				w=True
		elif L[1]=='/':
			if a/b==c:
				w=True
		if w == True:
			bases = '1'+bases
	if bases == '':
		bases = 'invalid'
	print(bases) 
