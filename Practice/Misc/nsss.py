n, m = map(int, input().split())
g = list(range(m+1))
d = ['' for _ in range(m+1)]
V = [0 for _ in range(m+1)]

for i in range(1, m+1):
    name, nxt = input().split()
    d[i] = name
    g[i] = int(nxt)

def getCycLen(n):
    a = g[n]
    i = 1
    while(a!=n):
        i+=1
        a = g[a]
    return i

def goNsteps(a, n):
    while(n>0):
        a = g[a]
        n -= 1
    return a

# print(g)
for i in range(1, m+1):
    if (not V[i]):
        k = i
        b = goNsteps(k, n % getCycLen(k))
        V[k] = b
        k = g[k]
        b = g[b]
        while k != i:
            V[k] = b
            k = g[k]
            b = g[b]
    print(d[V[i]])

