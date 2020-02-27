
# J

T = int(input())

def left(s,m):
	l = []
	p=0
	for c in s:
		if p: l.append(m[c][p]); p=0
		else: p=c
	if p:
		l.append(p)
	# print("left:", ''.join(l))
	return l  # don't join

def right(s,m):
	l = []
	it = iter(s)
	d = len(s)%2
	if d:
		l.append(next(it))
	p=0
	for c in it:
		if p: l.append(m[c][p]); p=0
		else: p=c
	# print("right:", ''.join(l))
	return l

def win(c, vowels='aeiou'):
	# M (1, True) wins on non-vowel
	return (c[0] not in vowels)

def search(s, m, player=0):  # Salah starts
	# returns player that wins from this node
	if len(s)==1:
		return win(s)  # who wins given s (S=0, M=1)
	# try left
	Lval = search(left(s,m), m, 1^player)
	# print("Lval: %d won search with player %d" % (Lval, 1^player))
	# if length is even, moves 'left'/'right' have same result
	# If current player can win with this move, make this move
	if len(s)%2==0 or Lval==player: return Lval  # choose left path since (we win) or (no other choice)
	return search(right(s,m), m, 1^player)

for t in range(T):
	m = {chr(97+x):{chr(97+y):c for y,c in enumerate(input())} for x in range(26)}
	s = input()
	print( "Salah" if search(s,m)==0 else "Marzo" )


