import random
print("200000 "+str(random.randrange(1,200000)))

L = list(range(1,200001))
random.shuffle(L)
print(" ".join([str(x) for x in L]))