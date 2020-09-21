nHairs, nCuts, cutTo = [int(x) for x in input().split()]
hair = list(map(int, input().split())) + [0]
#hair.insert(0, 0)
#hair.append(0)

# Initialize number of cuts
time = 0
inCut = False
for j in range(nHairs + 1):
    time += 1*(hair[j]>cutTo and not inCut)
    inCut = hair[j]>cutTo

T = []

for i in range(nCuts):
    line = input().split()
    if line[0] == '1':
        l = int(line[1])-1 #hair getting longer
        h = hair[l]
        hair[l] += int(line[2])
        if h <= cutTo and hair[l]>cutTo:
            #new cuttable hair
            time += 1
            time -= hair[l-1] > cutTo
            time -= hair[l+1] > cutTo
    else:
        T.append(str(time))
print('\n'.join(T))
