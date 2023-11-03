t, c, o, d, i = map(int, input().split())
dice = [4]*t + [6]*c + [8]*o + [12]*d + [20]*i

sums = [0 for _ in range(1001)]
sums[0] = 1
for di in dice:
	sums2 = [0 for _ in range(1001)]
	for k in range(1, di+1):
		for j in range(1001-k):
			sums2[j+k] += sums[j]
	sums = sums2
L = list(zip(sums, range(1001)))
# print(L)
L.sort()
L = L[::-1]
j = 0
while L[j][0] != 0:
	j += 1
L = L[:j]
print(' '.join([str(l[1]) for l in L]))