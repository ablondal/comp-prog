from random import randrange
N = 3*(10**5)+1
M = N
print(M)
for _ in range((M-1)//2):
	x = randrange(1,N)
	y = randrange(x,N)
	print(f"ADDRANGE {x} {y}")
	print(f"BUYAMT 10000")
print("TOTALCOST")