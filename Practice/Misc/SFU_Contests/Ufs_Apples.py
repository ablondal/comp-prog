n,m = map(int,input().split())

DP = [ [int(5e8) if _ else 0 for _ in range(m+1)] for x in range(n+1) ]

adj = [ [] for _ in range(n+1) ]

apples = [ 0 for _ in range(n+1) ]

root = -1

for i in range(1, n+1):
	parent, a = map(int,input().split())
	if parent:
		adj[parent].append(i)
	else: root = i
	apples[i] = a

def dfs(v):
	if v == 0:
		return 0

	while(len(adj[v])<2):
		adj[v].append(0)

	a = adj[v][0]
	b = adj[v][1]

	n_children = dfs(a) + dfs(b)

	for cut in range(min(n_children, m)+1):
		DP[v][cut] = min( [ (DP[a][t] + DP[b][cut-t]) for t in range(cut+1) ] )
		# print(v, cut, DP[v][cut])

	if n_children < m:
		DP[v][n_children+1] = DP[v][n_children] + apples[v]
		# print(v, n_children+1, DP[v][n_children+1])

	return n_children + 1

dfs(root)

print(DP[root][m])









