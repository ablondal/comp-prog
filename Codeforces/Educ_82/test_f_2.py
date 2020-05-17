print(300, 300, int(2e6))

for i in range(int(2e6)):
	print((i % 300)+1, (int((i%90000) // 300))+1, (int(i // 2e3))+1 )