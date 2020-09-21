n = int(input())
a = list(map(int, input().split()))[1:]
b = list(map(int, input().split()))[1:]
D = {}
c = 0
while(len(a)>0 and len(b)>0):
	if (D.get(tuple(a+b))!=None):
		break
	if (D.get(tuple(b+a))!=None):
		break
	D[tuple(a+b)]=0
	D[tuple(b+a)]=0
	c += 1
	if a[0]>b[0]:
		a.append(b[0])
		a.append(a[0])
		a = a[1:]
		b = b[1:]
	else:
		b.append(a[0])
		b.append(b[0])
		b = b[1:]
		a = a[1:]
if (len(a)==0):
	print(f"{c} 2")
elif (len(b)==0):
	print(f"{c} 1")
else:
	print("-1")
# print(a)
# print(b)