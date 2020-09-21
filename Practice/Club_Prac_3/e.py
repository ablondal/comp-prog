nBits = int(input())
bits = input()
target = input()

cost = [0 for x in range(nBits)]

def getc(i):
    if (i==-1): return 0
    elif (i==0): return 0 if bits[0] == target[0] else 1
    elif (bits[i]==target[i]): return cost[i-1]
    elif bits[i-1] != target[i-1] and bits[i] != bits[i-1]: return cost[i-2]+1
    else: return cost[i-1]+1



print(cost[nBits-1])