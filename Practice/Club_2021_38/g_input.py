from random import randrange
print(32)
h = (32 * 33) // 2
print(' '.join([str(randrange(100)) for _ in range(h)]))
row = 1
cct = 1
for _ in range(h):
	probs = [0, 0, 0, 0, 0]
	if cct != row:
		probs[0] = randrange(1,10)
	if cct != 1:
		probs[1] = randrange(1,10)
	if row != 32:
		probs[2] = randrange(1,10)
		probs[3] = randrange(1,10)
	probs[4] = 1
	s = sum(probs)
	for i in range(len(probs)):
		probs[i] /= s
	print(' '.join((str(p) for p in probs)))
	cct -= 1
	if cct == 0:
		row += 1
		cct = row