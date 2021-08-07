from random import randrange as rand
N = 1 * 10**5
K = 5
print(N, K)
print(' '.join(str(rand(0, 101)) for _ in range(K)))
for _ in range(N):
	print(' '.join(str(rand(-10000, 10000)) for _ in range(K)))