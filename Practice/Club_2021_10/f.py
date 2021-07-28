n = int(input());

from collections import Counter
from itertools import product
from array import array

arr = array('q', (0,)*(n*4))
for i in range(n):
	arr[i],arr[i+n],arr[i+2*n],arr[i+3*n] = map(int,input().split())
# print(arr)

x = Counter([a+b for a,b in product(arr[0:n], arr[n:2*n])])
y = Counter([a+b for a,b in product(arr[2*n:3*n], arr[3*n:4*n])])
tot = 0
for j in x.keys():
	if -j in y:
		tot += x[j]*y[-j]
print(tot)