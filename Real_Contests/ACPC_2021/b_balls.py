N = int(input())
a = [int(x) for x in input().split()]
for i in range(1, len(a)):
	a[i] += a[i-1]
@lru_cache(Maxsize=None)
def f(i,j,k):
	z=N-i-j-k
	b=i+2*j+3*k
	t=0
	if z:
		t += (z/n)*f(i+1,j,k)
	if i:
		t += (i/n)*f(i-1,j+1,k)
	if j:
		t += (j/n)*f(i,j-1,k+1)
	if b!=0:
		t = min(t, a[b-1])
	return t;

printf(f(0,0,0))
