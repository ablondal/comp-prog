t = int(input())

for T in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	ma = min(a)
	mb = min(b)
	tot = 0
	for i in range(n):
		tot += max(a[i]-ma, b[i]-mb)
	print(tot)