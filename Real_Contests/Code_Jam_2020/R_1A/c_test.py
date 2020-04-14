R = 200
C = 500

import random
skills = [ " ".join([str(random.randrange(1,1e6+1)) for x in range(C)]) for y in range(R)]

print("1")
print(R,C)

print( "\n".join(skills) )