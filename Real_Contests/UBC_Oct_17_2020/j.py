#done

adj = {}
n = int(input())
V = {}

for i in range(n):
	st = input().split()
	adj[st[0]] = st[1:]
	for a in st[1:]:
		if a not in adj.keys():
			adj[a] = [st[0]]
			V[a] = False
		if st[0] not in adj[a]:
			adj[a].append(st[0])
	V[st[0]] = False

s,t = input().split()

# for L in adj.keys():
# 	print(L + ' ' + ' '.join(adj[L]))

vis = []

def DFS(v):
	# print(v)
	if v not in V.keys() or V[v]: return False;
	if v == t: 
		return True;
	V[v] = True
	for e in adj[v]:
		if DFS(e):
			vis.append(v)
			return True;
	return False;

if DFS(s):
	print(' '.join(vis[::-1])+' '+t)
else:
	print("no route found")

