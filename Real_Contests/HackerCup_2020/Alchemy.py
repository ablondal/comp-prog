from collections import Counter
T = int(input())
for t in range(1, T+1):
	N = int(input())
	line = input()
	res = Counter(line)
	if (res['A'] - res['B'] in [1, -1]):
		print(f'Case #{t}: Y')
	else:
		print(f'Case #{t}: N')
