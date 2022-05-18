n = int(input())

n += 1

ans = 1
num = 1
for i in range(n+1, 2*n+1):
	ans *= i
for i in range(1, n+2):
	num *= i
print( ans // num)