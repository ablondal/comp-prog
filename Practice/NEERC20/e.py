def euclid(a,b):
	if b == 0:
		return (a, 1, 0)
	g, y, x = euclid(b, a%b)
	y -= (a//b) * x
	return (g, x, y)

n = int(input())
for _ in range(n):
	B,D = map(int, input().split())
	a = D
	b = B
	c = B*B

	g, x, y = euclid(a,b)

	if (c % g != 0):
		print("0");
		continue
	else:
		x = x * (c//g);
		y = y * (c//g);
		mink = 0;
		maxk = 0;

		if (x <= 0):
			mink = (abs(x) // (b//g)) + 1;
		else:
			mink = (x-1) // (b//g);
			mink *= -1;

		if (y <= 0):
			maxk = (abs(y) // (a//g)) + 1;
			maxk *= -1;
		else:
			maxk = (y-1) // (a//g);
		
		print(max(0, maxk-mink+1))