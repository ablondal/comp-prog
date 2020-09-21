n, m = map(int, input().split())

DP = [list(map(int, input().split())) for _ in range(n)]

# DP = [ [0 for x in range(m)] for _ in range(n)]

# DP[n-1][m-1] = p[n-1][m-1]

for y in range(n-2, -1, -1):
	DP[y][m-1] += DP[y+1][m-1]

for x in range(m-2, -1, -1):
	DP[n-1][x] += DP[n-1][x+1]

for y in range(n-2, -1, -1):
	for x in range(m-2, -1, -1):
		if ( (x+y) % 2 == 0):
			# print("hi")
			DP[y][x] += max(DP[y+1][x], DP[y][x+1])
		else:
			DP[y][x] += min(DP[y+1][x], DP[y][x+1])

print(DP[0][0])
# print('\n'.join([' '.join(map(str, d)) for d in DP]))