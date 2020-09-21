n = int(input()) + 1
MOD = 17
def exp(a, b):
	t = 1
	for i in range(b):
		t *= a
		t %= MOD
	return t
s = 0
for a in [2, 3, 5, 7]:
	s += exp(a, n % 16)
	s %= MOD
print(s)