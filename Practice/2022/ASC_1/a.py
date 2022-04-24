fin = open("china.in", 'r')
fout = open("china.out", 'w')

a = int(fin.read())

if a in (2, 4, 6)

b = a//2
if (a % 2 == 0):
	b -= 1

fout.write(str(ans))
fout.close()