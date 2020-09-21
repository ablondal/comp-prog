n = int(input())
alph = [chr(x) for x in range(ord('A'), ord('Z')+1) if chr(x)!='J']
f = 0
while(n!=0):
	if (not f):
		f=1
	else:
		print('')
	key = ''.join(input().split()).upper()
	key = 'I'.join(key.split('J'))

	tab = [ 'A' for y in range(25)]
	tabi = 0
	used = set()
	alp = 'A'

	for k in key:
		if k not in used:
			tab[tabi] = k
			tabi+=1
			used.add(k)

	for k in alph:
		if k not in used:
			tab[tabi] = k
			tabi+=1
			used.add(k)

	for x in range(n):
		enc = ''.join(input().split()).upper()
		enc = 'I'.join(enc.split('J'))

		digs = []
		enci = 0
		while(enci<len(enc)):
			if enci == len(enc)-1:
				digs.append(enc[-1]+'X')
				enci += 1
			elif enc[enci] == enc[enci+1]:
				digs.append(enc[enci]+'X')
				enci += 1
			else:
				digs.append(enc[enci:enci+2])
				enci += 2

		for i in range(len(digs)):
			if (digs[i] == 'XX'):
				digs[i] = 'YY'
				continue
			t1 = tab.index(digs[i][0])
			t2 = tab.index(digs[i][1])
			c1, r1 = t1%5, t1 // 5
			c2, r2 = t2%5, t2 // 5
			if (c1 == c2):
				r1 = (r1+1)%5
				r2 = (r2+1)%5
			elif (r1 == r2):
				c1 = (c1+1)%5
				c2 = (c2+1)%5
			else:
				c1, r1, c2, r2 = c2, r1, c1, r2
			digs[i] = tab[r1*5+c1]+tab[r2*5+c2]

		print(''.join(digs))



	n = int(input())


















