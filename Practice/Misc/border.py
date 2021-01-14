nCases = int(input())

outposts = [list(map(int, input().split())) for _ in range(nCases)]

outposts.sort()

biggestB = 0
nRedundant = 0
for outpost in outposts:
    if outpost[1] < biggestB:
        nRedundant += 1
    
    biggestB = max(biggestB, outpost[1])

print(nRedundant)
