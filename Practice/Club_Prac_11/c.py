t = int(input())

for T in range(t):
	n = int(input())
	w = list(map(int, input().split()))
	w = sorted(w)
	m_n = 0
	m_i = -1
	D = {}
	for i in range(101):
		D[i] = 0
	for i in range(n):
		D[w[i]] += 1
	for i in range(1,101):
		t = 0
		for j in range(1,i):
			t += min(D[j], D[i-j])
		if t > m_n:
			m_n = t
			m_i = i

	print(m_n//2)