available = [int(x) for x in input().split(' ')]
req = [int(x) for x in input().split(' ')]

n = 0
for i in range(3):
    n += max(0, req[i]-available[i])
print(n)
