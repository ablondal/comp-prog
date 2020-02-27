from math import ceil
def beats(l1,l2):
    # damage taken per turn
    dam_1 = max(l2[1]-l1[2], 0)  # at2 - df1
    dam_2 = max(l1[1]-l2[2], 0)  # at1 - df2
    if dam_1==0:
        if dam_2 != 0:
            # we never take damage and keep dealing damage
            return True
        else:
            return False  # neither takes damage; tie
    else:
        if dam_2==0:  # opponent never takes damage and we take damage
            return False
        else:
            # turns until health drops to 0 or below
            last_turn = int(ceil(l1[0] / dam_1))
            # hp1 - last_turn * dam_1 <= 0
            # and  hp - (last_turn-1)*dam_1 > 0
            # check opponent health not positive at end of previous turn
            # (when our health is still positive)
            if (last_turn-1)*dam_2 >= l2[0]:
                # we did more damage than their health: we won (their hp not positive)
                return True
            return False  # we lost or tied
# ex. taking 3 dam per turn, 4 hp
# end of 1st turn (1 hp left) is the last turn with positive hp
# ceil(4/3)-1 = 1
# ex taking 3 dam per turn, 6 hp
# same. end of 1st turn
# ceil(6/3)-1 = 1

N = int(input())
d = {}  # name: [hp,at,df]
for i in range(N):
    name, *rest = input().split()
    d[name] = list(map(int,rest))


pairs = [(a,b) for a in d for b in d if a!=b and beats(d[a],d[b])]
# a beats b

# print(pairs)
from collections import defaultdict
win = defaultdict(set)  # key wins against: ...
lose = defaultdict(set)
for p in pairs:
    win[p[0]].add(p[1])
    lose[p[1]].add(p[0])

triples = [[a,b,c]
    for a in d
    for b in win[a] if a<b  # a defeats b
    for c in lose[a] if b<c # c defeats a
    if c in win[b]]         # b defeats c
# a beats b, b beats c, c beats a

print(len(triples))
for t in triples:
    print(' '.join(t))