from collections import Counter
cols = Counter(open(0).read().split())
cols = [cols[e] for e in cols]

tot = 0

def nCr(n, r):
	res = 1
	for i in range(n-r+1, n+1):
		res *= i
	for i in range(1, r+1):
		res //= i
	return res

def n_orbs(cols, n, tt):
	if any([c % n for c in cols]):
		return 0
	if any([c < 0 for c in cols]):
		return 0
	r = 1
	tt = tt // n
	for c in cols:
		r *= nCr(tt, c//n)
		tt -= (c//n)
	return r

# Calculate 30 1-orbits
tot += n_orbs(cols, 1, 30)

# Calculate 10 3-orbs
tot += 20 * n_orbs(cols, 3, 30)

# Calculate 6 5-orbs
tot += 24 * n_orbs(cols, 5, 30)

# Calculate 2 1-orbits and 14 2-orbits
for i in range(len(cols)):
	for j in range(i, len(cols)):
		cols[i] -= 1
		cols[j] -= 1
		if i == j:
			tot += 15 * n_orbs(cols, 2, 28)
		else:
			tot += 30 * n_orbs(cols, 2, 28)
		cols[i] += 1
		cols[j] += 1

print(tot // 60)