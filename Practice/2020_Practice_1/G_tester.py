import random

N = random.randrange(1,100001)
N = 10000;

def gcd(a,b):
	if a==0:
		return b;
	return gcd(b%a,a);

print(N)
print (gcd(15,12))

vecs = set();

for i in range(N):
	x = random.randrange(-1000,1001)
	y = random.randrange(-1000,1001)
	d = gcd(x,y);
	x //= d;
	y //= d;
	while( (x,y) == (0,0) or (x,y) in vecs ):
		x = random.randrange(-1000,1001)
		y = random.randrange(-1000,1001)
		d = gcd(x,y);
		x //= d;
		y //= d;
	vecs.add( (x,y) );
	print (str(x) + " " + str(y))