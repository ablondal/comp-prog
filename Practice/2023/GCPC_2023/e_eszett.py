s = input().lower()
wds = [s.lower()]
i = 0
while s.find('ss', i) != -1:
	a = s.find('ss', i)
	wds.append(s[:a] + 'B' + s[a+2:])
	i = a+1
print('\n'.join(wds))