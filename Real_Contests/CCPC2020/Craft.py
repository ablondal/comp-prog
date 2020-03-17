# DONE

n, m = [int(x) for x in input().split()]
wants = [int(x) for x in input().split()]

deps = [[0 for j in range(n)] for i in range(n)]

for j in range(m):
	u,v,w = [int(x) for x in input().split()]
	deps[v][u] = w

w_tab = [[0 for j in range(n)] for i in range(n)]
V = [0 for i in range(n)]

def getwants(i):
	if V[i]: return

	w = [0 for l in range(n)]

	w[i] = 1

	for j in range(n):
		if deps[i][j] != 0:
			getwants(j)
			jw = w_tab[j]
			for k in range(n):
				w[k] += (jw[k])*deps[i][j]

	w_tab[i] = w
	V[i] = 1

totw = [0 for x in range(n)]
for i in range(n):
	getwants(i)
	w = w_tab[i]
	for j in range(n):
		totw[j] += w[j]*wants[i];

print(" ".join( [str(x) for x in totw] ));