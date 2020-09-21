import random

print(50, 1000)

def get_fruit(v):
	if (v > 25):
		return 'b'+(chr(ord('a')+v-26))
	else:
		return 'a'+(chr(ord('a')+v))

for i in range(50):
	print(get_fruit(i), random.randrange(1, 1001))

for i in range(1000):
	print(get_fruit(random.randrange(52)), random.randrange(1, 100001))