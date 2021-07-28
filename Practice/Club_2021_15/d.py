inp = input()[1:-1]
# print(inp)
if inp=='':
	print(0)
else:
	print(len(set(inp.split(', '))))
# S = set(inp)