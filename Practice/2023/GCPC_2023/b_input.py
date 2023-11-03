n = 10000
print(n)
from random import randrange
# pts = [ str(randrange(-50, 51)) + " " + str(randrange(-100, 101)) for _ in range(n)]
pts = [ f"{40} {i}" for i in range(n)]
print('\n'.join(pts))