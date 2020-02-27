

# L.py Candy jars


T = int(input())
for t in range(T):
	L = list(map(int,input().split()))
	N = L[0]
	jars = L[1:]
	M = N*(N-1)  # >0 since N>1
	# if all are 1<=j%M<=N-1 (lose) then bob wins
	print("Alice" if not all(1<=(j%M)<=(N-1) for j in jars) else "Bob")


