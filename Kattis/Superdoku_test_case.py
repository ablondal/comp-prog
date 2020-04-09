# Makes test cases for superdoku
import random
n = random.randrange(1,101)

k = random.randrange(0,3)

print(n,k)
L = [str(i) for i in range(1,n+1)]
if k>0:
	print(" ".join(L))
if k>1:
	K = L[:]
	while True:
		random.shuffle(K)
		for a,b in zip(L,K):
			if a==b:
				break;
		else:
			print(" ".join(K))
			break;