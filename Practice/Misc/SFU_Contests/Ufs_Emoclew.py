n = int(input())
names = [input() for _ in range(n)]
for name in names:
	split_name = name.split()
	new_name = []
	for component in split_name:
		new_name.append(component[::-1])
	print(' '.join(new_name))