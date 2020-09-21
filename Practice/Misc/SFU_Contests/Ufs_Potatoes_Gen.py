import random
print(1000, 1000)

print('\n'.join([' '.join([str(random.randrange(100001)) for x in range(1000)]) for _ in range(1000)]))