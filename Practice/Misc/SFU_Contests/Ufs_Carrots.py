n = int(input())

h = [-1] + list(map(int, input().split()))

H = sorted(list(range(n+1)), key = lambda a: h[a])

print(H[-2])