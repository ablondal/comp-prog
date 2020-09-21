t = int(input())

for i in range(t):
	a = int(input())
	arr = list(map(int, input().split()))
	a2 = sorted(arr)
	while(len(arr) > 1):
		j = arr.index(min(arr))
		if (j != 0 and arr[j-1]==arr[j]+1) or (j!=len(arr)-1 and arr[j+1] in [arr[j], arr[j]+1]):
			arr.pop(j)
		else:
			break
	if (len(arr) == 1):
		print("YES")
	else:
		print("NO")