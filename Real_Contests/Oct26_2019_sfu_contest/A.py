import math
import functools

# get number of permutations greater
@functools.lru_cache(maxsize=512)
def G(n):
	k = len(n)
	if k == 1:
		return 0
	return G(n[1:]) + (S(n)* math.factorial(k-1))

def S(n):
	count = 0
	for x in n[1:]:
		if x>n[0]:
			count +=1
	return count

def fastpow(a,b):
	if b==0: return 1
	d = a if b%2 else 1
	return d * fastpow(a**2, b//2)

EPS = 1e-12

# geometric series sum
def P(r, k):
	if r == 1:
		return 0
	infsum = r/(r-1)
	# return -1 + infsum*(1 - (1/fastpow(r,(k+1)) ) )

	retval = -1 + infsum
	prev_proposed_inc = 0
	proposed_inc = 10
	inc = r
	i = 0
	while abs(proposed_inc-prev_proposed_inc) > EPS and i < k+1:
		i +=1
		prev_proposed_inc = proposed_inc
		proposed_inc = infsum*(1/inc)
		inc *= r
	retval -= proposed_inc
	return retval
	#return -1 + infsum - infsum*((1/r)**(k+1))

T = int(input())

for cases in range(T):
	n = list(str(int(input())))
	terrible = sorted(n)
	n = [terrible.index(x) for x in n]

	k = G(tuple(n))
	r = math.factorial(len(n))
	print('{:.9f}'.format(abs(P(r, k))))
